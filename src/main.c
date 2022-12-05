#include "display.h"
bool is_running = false;

void setup(void)
{
    // Allocating memory for color buffer
    color_buffer = (uint32_t *)malloc(sizeof(uint32_t) * window_width * window_height);
    // Creating a texture to map color buffer
    color_buffer_texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        window_width,
        window_height);
}

void process_input(void)
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        is_running = false;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
            is_running = false;
        break;
    }
}

void update(void) {}

void render(void)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    draw_grid();
    // border color white, background color green vignette
    draw_rect(100, 100, 400, 100, 0xFF00FF00, 0xFFFFFFFF);
    render_color_buffer();
    clear_color_buffer(0x000000);
    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{
    is_running = initialize_window();
    setup();

    while (is_running)
    {
        process_input();
        update();
        render();
    }
    destroy_window();
    return 0;
}
