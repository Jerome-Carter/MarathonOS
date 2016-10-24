#include "headers/vga.h"
#include "headers/port.h"
#include "headers/helpers.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

uint8_t vga_make_color(enum vga_color foreground, enum vga_color background) {
    return foreground | background << 4;
}

uint16_t vga_make_char(unsigned char character, uint8_t color) {
    return (uint16_t) character | (uint16_t) color << 8;
}

void vga_set_cursor(size_t row, size_t column) {
    cursor_row = row;
    cursor_column = column;
    vga_row = cursor_row;
    vga_column = cursor_column;
    unsigned short position= row * 80 + column;
    outb(CURSOR_CMD_PORT, CURSOR_HIGH);
    outb(CURSOR_DATA_PORT, (unsigned char)(position&0xFF));
    outb(CURSOR_CMD_PORT, CURSOR_LOW);
    outb(CURSOR_DATA_PORT, (unsigned char)((position>>8)&0xFF));
}

void vga_set_color(uint8_t color) {
    vga_color = color;
}

void vga_init(enum vga_color foreground, enum vga_color background) {
    vga_row = 0;
    vga_column = 0;
    vga_color = vga_make_color(foreground, background);
    vga_address = (uint16_t*) 0xB8000;
    vga_set_cursor(vga_row, vga_column);
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            vga_address[index] = vga_make_char(' ', vga_color);
        }
    }
}

void vga_clear_line(size_t from, size_t to) {
    uint16_t start = 80 * from;
    for (uint16_t i = start; i < (80 * (to + 1)); i++) {
        vga_address[i] = vga_make_char(' ', vga_color);
    }
}

void vga_clear() {
    vga_clear_line(0, VGA_HEIGHT - 1);
    vga_set_cursor(0, 0);
}

void vga_scroll(uint16_t lines) {
    for (uint16_t i = 0; i < VGA_WIDTH * (VGA_HEIGHT - 1); i++) {
        vga_address[i] = vga_address[i + VGA_WIDTH * lines];
    }
    vga_clear_line(VGA_HEIGHT - 1 - lines, VGA_HEIGHT - 1);
    if ((cursor_row - lines) < 0) {
        vga_row = 0;
        vga_column = 0;
        vga_set_cursor(0, 0);
    } else {
        vga_row = cursor_row - lines;
        vga_set_cursor((cursor_row -= lines), 0);
    }
}

void vga_scroll_down() {
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            const size_t lookahead_index = index + VGA_WIDTH;

            if (y == 24)
                vga_address[index] = vga_make_char(' ', vga_color);
            else
                vga_address[index] = vga_address[lookahead_index];
        }
    }
    vga_row = 24;
    vga_column = 0;
}

void vga_newline() {
    vga_column = 0;
    if (++vga_row == VGA_HEIGHT)
        vga_scroll_down();
    vga_set_cursor(vga_row, vga_column);
}

void vga_put_index(char c, uint8_t color, size_t row, size_t column) {
    const size_t index = row * VGA_WIDTH + column;
    vga_address[index] = vga_make_char(c, color);
}

void vga_put_char(char c) {
    switch (c) {
        case (0x08) :
            if (vga_column > 0) {
                vga_address[vga_row * VGA_WIDTH + (vga_column - 1)] = vga_make_char(' ', vga_color);
                vga_set_cursor(vga_row, (vga_column - 1));
            }
            break;
        case (0x09) :
            vga_set_cursor(cursor_row, (cursor_column + 8));
            break;
        case (0x0A) :
            vga_newline();
            break;
        case (0x0D) :
            vga_set_cursor(cursor_row, 0);
            break;
        default:
            vga_put_index(c, vga_color, vga_row, vga_column);
            if (++vga_column == VGA_WIDTH) {
                vga_column = 0;
                if (++vga_row == VGA_HEIGHT)
                    vga_scroll_down();
            }
            vga_set_cursor(vga_row, vga_column);
            break;
    }
}

void print(const char* data) {
    for (size_t i = 0; i < strlen(data); i++)
        vga_put_char(data[i]);
}
