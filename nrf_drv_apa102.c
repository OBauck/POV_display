

#include "nrf.h"
#include "nrf_drv_spi.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "nrf_drv_apa102.h"

#define SPI_INSTANCE  0 /**< SPI instance index. */
static const nrf_drv_spi_t spi = NRF_DRV_SPI_INSTANCE(SPI_INSTANCE);  /**< SPI instance. */

#define BYTES_PER_PIXEL	4
#define SPI_TX_BYTES	((NR_OF_LEDS+1)*BYTES_PER_PIXEL+1)

static uint8_t       m_tx_buf[SPI_TX_BYTES];

static pixel_t red = {0x1F, 0xFF, 0, 0};
static pixel_t green = {0x1F, 0, 0xFF, 0};
static pixel_t blue = {0x1F, 0, 0, 0xFF};
static pixel_t pixel_off = {0, 0xFF, 0xFF, 0xFF};

void spi_event_handler(nrf_drv_spi_evt_t const * p_event)
{

}	

void nrf_drv_apa102_init(uint8_t data_pin, uint8_t clock_pin)
{
    nrf_drv_spi_config_t spi_config = NRF_DRV_SPI_DEFAULT_CONFIG;
    spi_config.ss_pin   = SPI_SS_PIN;
    spi_config.miso_pin = SPI_MISO_PIN;
    spi_config.mosi_pin = data_pin;
    spi_config.sck_pin  = clock_pin;
	spi_config.frequency = NRF_DRV_SPI_FREQ_8M;
    APP_ERROR_CHECK(nrf_drv_spi_init(&spi, &spi_config, spi_event_handler));
	
	for(uint8_t i = 0; i < NR_OF_LEDS; i++)
	{
		nrf_drv_apa102_set_pixel(i, &pixel_off);
	}
	
	nrf_drv_apa102_update();
}

void nrf_drv_apa102_set_pixel(uint8_t pixel_nr, pixel_t *p_pixel)
{
	m_tx_buf[(pixel_nr+1)*4] = 0xE0 | p_pixel->brightness;	//brightness is 5 bit: 111xxxxx
	m_tx_buf[(pixel_nr+1)*4+1] = p_pixel->blue;
	m_tx_buf[(pixel_nr+1)*4+2] = p_pixel->green;
	m_tx_buf[(pixel_nr+1)*4+3] = p_pixel->red;
}

uint32_t nrf_drv_apa102_update(void)
{
	return nrf_drv_spi_transfer(&spi, m_tx_buf, SPI_TX_BYTES, NULL, 0);
}

void nrf_drv_apa102_test(void)
{
	while(1)
	{
		for(uint8_t i = 0; i < 3; i++)
		{
			for(uint8_t j = 0; j < NR_OF_LEDS; j+=3)
			{
				nrf_drv_apa102_set_pixel((j+i)%NR_OF_LEDS, &red);
				nrf_drv_apa102_set_pixel((j+i+1)%NR_OF_LEDS, &blue);
				nrf_drv_apa102_set_pixel((j+i+2)%NR_OF_LEDS, &green);
			}

			APP_ERROR_CHECK(nrf_drv_spi_transfer(&spi, m_tx_buf, SPI_TX_BYTES, NULL, 0)); 
			nrf_delay_ms(500);
		}
	}	
}
