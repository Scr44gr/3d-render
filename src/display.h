#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern uint32_t *color_buffer;
extern SDL_Texture *color_buffer_texture;

extern int window_width;
extern int window_height;

bool initialize_window(void);
void destroy_window(void);
void clear_color_buffer(uint32_t color);
void render_color_buffer(void);
void draw_grid(void);
void draw_pixel(int x, int y, uint32_t color);
void draw_rect(int x, int y, int width, int height, uint32_t color, uint32_t border_color);

#endif