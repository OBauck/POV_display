
#ifndef APA102_H
#define APA102_H

#include <stdint.h>

//max 63 (will give 253 bytes SPI buffer)
#define NR_OF_LEDS	30
#define LED_STRIP_ACROSS_CENTER

#ifdef LED_STRIP_ACROSS_CENTER
#define NR_OF_PIXELS NR_OF_LEDS/2
#else
#define NR_OF_PIXELS NR_OF_LEDS
#endif

typedef struct
{
	uint8_t brightness;
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	
} pixel_t;

void nrf_drv_apa102_init(uint8_t data_pin, uint8_t clock_pin);
uint32_t nrf_drv_apa102_update(void);
void nrf_drv_apa102_test(void);
void nrf_drv_apa102_set_pixel(uint8_t pixel_nr, pixel_t *p_pixel);

#endif //APA102_H
