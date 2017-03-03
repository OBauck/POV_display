
#ifndef POV_DISPLAY_H__
#define POV_DISPLAY_H__

#include <stdint.h>
#include <stdbool.h>
#include "nrf_drv_apa102.h"

#define APP_TIMER_PRESCALER             15     // Value of the RTC1 PRESCALER register.
#define APP_TIMER_OP_QUEUE_SIZE         3     // Size of timer operation queues.

#define PIXEL_RED (pixel_t){0x1F, 0xFF, 0, 0}
#define PIXEL_GREEN (pixel_t){0x1F, 0, 0xFF, 0}
#define PIXEL_BLUE (pixel_t){0x1F, 0, 0, 0xFF}
#define PIXEL_YELLOW (pixel_t){0x1F, 0xFF, 0x7F, 0}
#define PIXEL_PURPLE (pixel_t){0x1F, 0xFF, 0, 0xFF}
#define PIXEL_BLUEGREEN (pixel_t){0x1F, 0, 0xFF, 0x7F}
#define PIXEL_WHITE (pixel_t){0x1F, 0xFF, 0xFF, 0xFF}
#define PIXEL_OFF (pixel_t){0x1F, 0, 0, 0}

typedef struct
{
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
} time_t;

void POV_display_init(void);
void POV_display_clear(void);
uint32_t POV_display_put_string(uint8_t start_strip, char *str, pixel_t color);

void POV_display_clock_init(time_t time, bool analog);
void POV_display_clock_set_time(time_t time);
void POV_display_clock_start(void);
void POV_clock_timer_handler(void * p_context);

#endif //POV_DISPLAY
