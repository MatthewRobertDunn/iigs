#pragma section code = text
#pragma section data = textdata
#include "font.h"
#include <string.h>
#include "fastscroll.h"
#define LINE_HEIGHT 160
#define CHAR_WIDTH 4
#define CHAR_HEIGHT 8
#define SCREEN_MAX 32000
#define ROW_MAX 25
#define COLUMN_MAX 40
#define VIDEO 0x012000
#define ROW_HEIGHT LINE_HEIGHT * CHAR_HEIGHT
static unsigned far int cursor = 0;
static unsigned far int row = 0;
static unsigned far int column = 0;

void draw_line(char charLine, unsigned int offset, unsigned char color);

void draw_line(char charLine, unsigned int offset, unsigned char color)
{
	char *video = (char *)VIDEO;
	char *drawStart;
	int x;
	char out = 0;

	// IIGS pixels are two 4bits packed into 1 byte. High then low.
	drawStart = video + offset;
	for (x = 0; x < 4; x++)
	{
		// If left most bit is 1 shift color into the top 4 bits
		if (charLine & 0x80)
		{
			out = color << 4;
		}
		else // else start at 0
		{
			out = 0;
		}

		// Get next bit of font
		charLine = charLine << 1;

		// If left most bit is 1 set color into the low 4 bits
		if (charLine & 0x80)
		{
			out = out | color;
		}

		drawStart[x] = out;

		// get next bit of font
		charLine = charLine << 1;
	}
}

void _newline()
{
	row += 1;
	column = 0;

	if(row >= ROW_MAX){
		row = ROW_MAX - 1;
		fastScroll();
	}

	cursor = (row * LINE_HEIGHT * CHAR_HEIGHT);
}

// Draws a character to the screen in a given color, keep strack of the cursor position
void _putchar(char character, unsigned char color)
{
	unsigned char *template;

	// Handle special characters
	if (character == '\n')
	{
		_newline();
		return;
	}

	// Find the right character in our font
	template = console_font_8x8[character];

	// draw 8 lines of our font
	draw_line(template[0], cursor, color);
	draw_line(template[1], cursor + LINE_HEIGHT, color);
	draw_line(template[2], cursor + LINE_HEIGHT * 2, color);
	draw_line(template[3], cursor + LINE_HEIGHT * 3, color);
	draw_line(template[4], cursor + LINE_HEIGHT * 4, color);
	draw_line(template[5], cursor + LINE_HEIGHT * 5, color);
	draw_line(template[6], cursor + LINE_HEIGHT * 6, color);
	draw_line(template[7], cursor + LINE_HEIGHT * 7, color);
	// Advance the cursor 8 pixels (4 bytes)
	cursor += CHAR_WIDTH;
	column += 1;
	// If we got to the end of the line move to the next line
	if (column >= COLUMN_MAX)
	{
		_newline();
	}
}
