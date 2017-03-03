/* Copyright (c) 2015 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

#include "app_util_platform.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "boards.h"
#include "app_error.h"
#include "nrf_drv_apa102.h"
#include "POV_display.h"
#include "nrf_drv_clock.h"
#include "app_timer.h"
#include "nrf_delay.h"

static void lfclk_request(void)
{
	uint32_t err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);
    nrf_drv_clock_lfclk_request(NULL);
}

int main(void)
{
	NRF_POWER->TASKS_CONSTLAT = 1;
	NRF_CLOCK->EVENTS_HFCLKSTARTED = 1;
	NRF_CLOCK->TASKS_HFCLKSTART = 1;
	while(NRF_CLOCK->EVENTS_HFCLKSTARTED == 0);
	
	lfclk_request();
	APP_TIMER_INIT(APP_TIMER_PRESCALER, APP_TIMER_OP_QUEUE_SIZE, false);
	
	POV_display_init();
	POV_display_put_string(0, "HELLO WORLD", PIXEL_RED);
	
	POV_display_clock_init((time_t){22,30,0}, false);
	POV_display_clock_start();
	
	for(;;)
	{
		/*
		POV_display_clear();
		POV_display_put_string(0, "RED", PIXEL_RED);
		nrf_delay_ms(2000);
		POV_display_clear();
		POV_display_put_string(0, "BLUE", PIXEL_BLUE);
		nrf_delay_ms(2000);
		POV_display_clear();
		POV_display_put_string(0, "GREEN", PIXEL_GREEN);
		nrf_delay_ms(2000);
		POV_display_clear();
		POV_display_put_string(0, "PURPLE", PIXEL_PURPLE);
		nrf_delay_ms(2000);
		POV_display_clear();
		POV_display_put_string(0, "YELLOW", PIXEL_YELLOW);
		nrf_delay_ms(2000);
		POV_display_clear();
		POV_display_put_string(0, "BLUEGREEN", PIXEL_BLUEGREEN);
		nrf_delay_ms(2000);
		POV_display_clear();
		POV_display_put_string(0, "WHITE", PIXEL_WHITE);
		nrf_delay_ms(2000);
		*/
	}
}
