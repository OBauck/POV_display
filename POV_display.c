
#include <string.h>

#include "nrf.h"
#include "nrf_gpio.h"
#include "app_util_platform.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_apa102.h"
#include "nrf_delay.h"
#include "nrf_drv_timer.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_gpiote.h"
#include "font.h"
#include "POV_display.h"
#include "app_timer.h"

#define NR_OF_UPDATES_PER_ROUND 180
//#define LED_STRIP_ACROSS_CENTER
#define FILTER_ALPHA	0.0f	//variable for the EMA filter on the display interval. Lower value means we trust more on the current measurement.

#define HALL_EFFECT_PIN 	31
#define LED_STRIP_DATA_PIN	3
#define LED_STRIP_CLOCK_PIN	4

typedef struct
{
	pixel_t pixels[NR_OF_PIXELS];

} stripe_t;

static time_t m_current_time;
static bool m_clock_analog;

static stripe_t stripe_empty;

APP_TIMER_DEF(m_POV_clock_timer_id);

static nrf_drv_timer_t timer_interval = NRF_DRV_TIMER_INSTANCE(3);
static nrf_drv_timer_t timer_measure = NRF_DRV_TIMER_INSTANCE(4);

static volatile float strip_display_interval = 220*16*240/NR_OF_UPDATES_PER_ROUND;

static uint8_t buffer_in_use = 0;
static bool m_buffer_updated = false;

static stripe_t stripes_buffer_1[NR_OF_UPDATES_PER_ROUND];
static stripe_t stripes_buffer_2[NR_OF_UPDATES_PER_ROUND];

static volatile uint8_t stripe_counter = 0;

static pixel_t pixel_off = {0x1F, 0, 0, 0};

#ifdef LED_STRIP_ACROSS_CENTER
void set_stripe(stripe_t *stripe_low, stripe_t *stripe_high)
{
	for(uint8_t i = 0; i < NR_OF_PIXELS; i++)
	{
		nrf_drv_apa102_set_pixel(i + NR_OF_PIXELS, &stripe_high->pixels[i]);
		nrf_drv_apa102_set_pixel(NR_OF_PIXELS - i - 1, &stripe_low->pixels[i]);
	}
	
	nrf_drv_apa102_update();
}
#else
void set_stripe(stripe_t *stripe)
{
	for(uint8_t i = 0; i < NR_OF_PIXELS; i++)
	{
		nrf_drv_apa102_set_pixel(i, &stripe->pixels[i]);
	}
	
	nrf_drv_apa102_update();
}
#endif

void in_pin_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
	
	uint32_t round_time = nrf_drv_timer_capture_get(&timer_measure, NRF_TIMER_CC_CHANNEL0);
	float interval_measured = (round_time + NR_OF_UPDATES_PER_ROUND / 2) / NR_OF_UPDATES_PER_ROUND;
	strip_display_interval = strip_display_interval * FILTER_ALPHA + interval_measured * (1.0f - FILTER_ALPHA);
	
	nrf_drv_timer_extended_compare(&timer_interval, (nrf_timer_cc_channel_t)0, (uint32_t)strip_display_interval, NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK, true);
	nrf_drv_timer_clear(&timer_interval);
	
	stripe_counter = 0;
	
	if(m_buffer_updated == true)
	{
		buffer_in_use ^= 1;
		m_buffer_updated = false;
	}
	
	if(buffer_in_use == 0)
	{
		set_stripe(&stripes_buffer_1[stripe_counter], &stripes_buffer_1[(stripe_counter + NR_OF_UPDATES_PER_ROUND/2) % NR_OF_UPDATES_PER_ROUND]);
	}
	else
	{
		set_stripe(&stripes_buffer_2[stripe_counter], &stripes_buffer_2[(stripe_counter + NR_OF_UPDATES_PER_ROUND/2) % NR_OF_UPDATES_PER_ROUND]);
	}
	stripe_counter++;
	
	/*
	char str[20];
	memset(str, 0, 20);
	sprintf(str, "Int: %d", (uint32_t)strip_display_interval);
	POV_display_put_string(0, str, red);
	*/
}

void timer_interval_handler(nrf_timer_event_t event_type, void * p_context)
{
	if(stripe_counter < NR_OF_UPDATES_PER_ROUND)
	{
		if(buffer_in_use == 0)
		{
			set_stripe(&stripes_buffer_1[stripe_counter], &stripes_buffer_1[(stripe_counter + NR_OF_UPDATES_PER_ROUND/2) % NR_OF_UPDATES_PER_ROUND]);
		}
		else
		{
			set_stripe(&stripes_buffer_2[stripe_counter], &stripes_buffer_2[(stripe_counter + NR_OF_UPDATES_PER_ROUND/2) % NR_OF_UPDATES_PER_ROUND]);
		}
		stripe_counter++;
	}
}

void timer_measure_handler(nrf_timer_event_t event_type, void * p_context)
{
	
}

void hall_effect_pin_init()
{
	uint32_t err_code;
	
	//gpiote for hall effect sensor
	if(!nrf_drv_gpiote_is_init())
	{
		err_code = nrf_drv_gpiote_init();
		APP_ERROR_CHECK(err_code);
	}
	
	nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_HITOLO(true);
    in_config.pull = NRF_GPIO_PIN_PULLUP;

    err_code = nrf_drv_gpiote_in_init(HALL_EFFECT_PIN, &in_config, in_pin_handler);
    APP_ERROR_CHECK(err_code);
	
    nrf_drv_gpiote_in_event_enable(HALL_EFFECT_PIN, true);
}

void sync_timer_init()
{
	uint32_t err_code;
	static nrf_ppi_channel_t ppi_channel1;
	static nrf_ppi_channel_t ppi_channel2;
	static nrf_ppi_channel_t ppi_channel3;
	
	uint32_t in_evt_addr;
    uint32_t timer_measure_clear_task_addr;
	uint32_t timer_measure_capture_task_addr;
	uint32_t timer_interval_clear_task_addr;
	
	nrf_drv_timer_config_t timer_cfg = NRF_DRV_TIMER_DEFAULT_CONFIG;
	
	err_code = nrf_drv_timer_init(&timer_interval, &timer_cfg, timer_interval_handler);
	APP_ERROR_CHECK(err_code);
	
	err_code = nrf_drv_timer_init(&timer_measure, &timer_cfg, timer_measure_handler);
	APP_ERROR_CHECK(err_code);
	
	//capture measure timer on in pin event
	err_code = nrf_drv_ppi_channel_alloc(&ppi_channel1);
    APP_ERROR_CHECK(err_code);

    in_evt_addr = nrf_drv_gpiote_in_event_addr_get(HALL_EFFECT_PIN);
    timer_measure_capture_task_addr = nrf_drv_timer_capture_task_address_get(&timer_measure, (nrf_timer_cc_channel_t)0);

    err_code = nrf_drv_ppi_channel_assign(ppi_channel1, in_evt_addr, timer_measure_capture_task_addr);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_drv_ppi_channel_enable(ppi_channel1);
    APP_ERROR_CHECK(err_code);
	
	//clear measure timer on in pin event
	err_code = nrf_drv_ppi_channel_alloc(&ppi_channel2);
    APP_ERROR_CHECK(err_code);

    timer_measure_clear_task_addr = nrf_drv_timer_task_address_get(&timer_measure, NRF_TIMER_TASK_CLEAR);

    err_code = nrf_drv_ppi_channel_assign(ppi_channel2, in_evt_addr, timer_measure_clear_task_addr);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_drv_ppi_channel_enable(ppi_channel2);
    APP_ERROR_CHECK(err_code);
	
	nrf_drv_timer_extended_compare(&timer_interval, (nrf_timer_cc_channel_t)0, 220*16*240/NR_OF_UPDATES_PER_ROUND, NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK, true);
	
	//clear interval timer on in pin event
	err_code = nrf_drv_ppi_channel_alloc(&ppi_channel3);
    APP_ERROR_CHECK(err_code);

    timer_interval_clear_task_addr = nrf_drv_timer_task_address_get(&timer_interval, NRF_TIMER_TASK_CLEAR);

    err_code = nrf_drv_ppi_channel_assign(ppi_channel3, in_evt_addr, timer_interval_clear_task_addr);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_drv_ppi_channel_enable(ppi_channel3);
    APP_ERROR_CHECK(err_code);
	
	//enable (start) timers
	nrf_drv_timer_enable(&timer_interval);
	nrf_drv_timer_enable(&timer_measure);
}

//this will update the display to use the next buffer
void POV_display_update(void)
{
	m_buffer_updated = true;
}

void POV_display_clear(void)
{
	if(m_buffer_updated == true)
	{
		return;		//TODO: error code
	}
	if(buffer_in_use == 0)
	{
		for(uint16_t i = 0; i < sizeof(stripes_buffer_2)/sizeof(stripe_t); i++)
		{
			memcpy(&stripes_buffer_2[i], &stripe_empty, sizeof(stripe_t));
		}
	}
	else
	{
		for(uint16_t i = 0; i < sizeof(stripes_buffer_1)/sizeof(stripe_t); i++)
		{
			memcpy(&stripes_buffer_1[i], &stripe_empty, sizeof(stripe_t));
		}
	}
}

void POV_display_set_stripe(uint8_t stripe_nr, uint16_t stripe, pixel_t color)
{
	if(m_buffer_updated == true)
	{
		return;		//TODO: error code
	}
	if(buffer_in_use == 0)
	{
		for(uint8_t i = 0; i < NR_OF_PIXELS; i++)
		{
			if((stripe << i) & 0x8000)
			{
				memcpy(&stripes_buffer_2[stripe_nr].pixels[i], &color, sizeof(pixel_t));
			}
			else
			{
				memcpy(&stripes_buffer_2[stripe_nr].pixels[i], &pixel_off, sizeof(pixel_t));
			}
		}
	}
	else
	{
		for(uint8_t i = 0; i < NR_OF_PIXELS; i++)
		{
			if((stripe << i) & 0x8000)
			{
				memcpy(&stripes_buffer_1[stripe_nr].pixels[i], &color, sizeof(pixel_t));
			}
			else
			{
				memcpy(&stripes_buffer_1[stripe_nr].pixels[i], &pixel_off, sizeof(pixel_t));
			}
		}
	}
}

uint32_t POV_display_put_string(uint8_t start_strip, char *str, pixel_t color)
{
	char c;
	uint8_t width;
	uint16_t offset, stripe;
	uint8_t strip_count = start_strip;
	uint8_t height = arial_8ptFontInfo.char_height;
	
	for(uint8_t i = 0; i < strlen(str); i++)
	{
		//add space between characters
		POV_display_set_stripe(strip_count, 0, color);
		strip_count++;
		POV_display_set_stripe(strip_count, 0, color);
		strip_count++;
		
		if(strip_count > NR_OF_UPDATES_PER_ROUND)
		{
			//out of bounds
			return NRF_ERROR_NO_MEM;
		}
		
		c = str[i];
		
		if(c == ' ')
		{
			width = arial_8ptFontInfo.space_char_width;
			for(uint8_t i = 0; i < width; i++)
			{
				POV_display_set_stripe(strip_count, 0, color);
				strip_count++;
			}
		}
		else if((c < arial_8ptFontInfo.start_char) || (c > arial_8ptFontInfo.end_char))
		{
			//unsupported character
			return NRF_ERROR_INVALID_PARAM;
		}
		else
		{
			width = arial_8ptDescriptors[c - arial_8ptFontInfo.start_char].char_width;
			offset = arial_8ptDescriptors[c - arial_8ptFontInfo.start_char].bitmap_offset;
			
			for(uint8_t i = 0; i < width; i++)
			{
				if(strip_count > NR_OF_UPDATES_PER_ROUND)
				{
					//out of bounds
					return NRF_ERROR_NO_MEM;
				}
				
				stripe = arial_8ptBitmaps[offset+i*2+1] + (uint16_t)(arial_8ptBitmaps[offset+i*2]<<8);
				stripe >>= (16 - height);	//move character to the top, 16 bit variable
				POV_display_set_stripe(strip_count, stripe, color);
				strip_count++;
			}
		}
	}
	return NRF_SUCCESS;
}

void POV_display_init()
{
	nrf_drv_apa102_init(LED_STRIP_DATA_PIN, LED_STRIP_CLOCK_PIN);
	
	static stripe_t stripe_red;
	static stripe_t stripe_green;
	static stripe_t stripe_blue;
	
	for(uint8_t i = 0; i < NR_OF_PIXELS; i++)
	{
		stripe_red.pixels[i].red = 0xFF;
		stripe_red.pixels[i].brightness = 0x1F;
		
		stripe_green.pixels[i].green = 0xFF;
		stripe_green.pixels[i].brightness = 0x1F;
		
		stripe_blue.pixels[i].blue = 0xFF;
		stripe_blue.pixels[i].brightness = 0x1F;
		
		stripe_empty.pixels[i].brightness = 0x1F;
	}
	
	set_stripe(&stripe_red, &stripe_green);
	nrf_delay_ms(300);
	
	set_stripe(&stripe_green, &stripe_blue);
	nrf_delay_ms(300);
	
	set_stripe(&stripe_blue, &stripe_red);
	nrf_delay_ms(300);
	
	POV_display_clear();
	
	hall_effect_pin_init();
	sync_timer_init();
}

void POV_display_clock(time_t time, bool analog)
{
	static char str[12];
	POV_display_clear();
	
	if(analog)
	{
		if(time.hour >= 12)
		{
			time.hour -= 12;
		}
		
		POV_display_set_stripe(time.hour*NR_OF_UPDATES_PER_ROUND/12, 0xFC00, PIXEL_RED);
		POV_display_set_stripe(time.minute*NR_OF_UPDATES_PER_ROUND/60, 0xFF00, PIXEL_GREEN);
		POV_display_set_stripe(time.second*NR_OF_UPDATES_PER_ROUND/60, 0xFFC0, PIXEL_BLUE);
	}
	else
	{
		
		memset(str, 0, 12);
		sprintf(str, "%d:%d:%d", time.hour, time.minute, m_current_time.second);
		POV_display_put_string(0, str, PIXEL_GREEN);
	}
}

void POV_clock_timer_handler(void * p_context)
{
	m_current_time.second++;
	
	if(m_current_time.second >= 60)
	{
		m_current_time.second = 0;
		m_current_time.minute++;
		if(m_current_time.minute >= 60)
		{
			m_current_time.minute = 0;
			m_current_time.hour++;
			if(m_current_time.hour >= 24)
			{
				m_current_time.hour = 0;
			}
		}
	}
	
    POV_display_clock(m_current_time, m_clock_analog);
	POV_display_update();
}

void POV_display_clock_init(time_t time, bool analog)
{
	uint32_t err_code;

    // Create timers
    err_code = app_timer_create(&m_POV_clock_timer_id,
                                APP_TIMER_MODE_REPEATED,
                                POV_clock_timer_handler);
    APP_ERROR_CHECK(err_code);
	
	memcpy(&m_current_time, &time, sizeof(time_t));
	m_clock_analog = analog;
}

void POV_display_clock_set_time(time_t time)
{
	memcpy(&m_current_time, &time, sizeof(time_t));
}

void POV_display_mode(bool analog)
{
	m_clock_analog = analog;
}

void POV_display_clock_start(void)
{
	uint32_t err_code;
	
	err_code = app_timer_start(m_POV_clock_timer_id, APP_TIMER_TICKS(1000, APP_TIMER_PRESCALER), NULL);
	APP_ERROR_CHECK(err_code);
}

void POV_display_clock_stop(void)
{
	app_timer_stop(m_POV_clock_timer_id);
}

