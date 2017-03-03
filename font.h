
#include <stdint.h>

typedef struct
{
	uint8_t char_width;
	uint16_t bitmap_offset;
} font_char_info_t;

typedef struct 
{
	uint8_t char_height;
	char start_char;
	char end_char;
	uint8_t space_char_width;
	const font_char_info_t *descriptor;
	const uint8_t *bitmap;
	
} font_info_t;

/* Font data for Arial 8pt */
extern const uint8_t arial_8ptBitmaps[];
extern const font_info_t arial_8ptFontInfo;
extern const font_char_info_t arial_8ptDescriptors[];
