#include "mlx.h"
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define RECT_SIZE 50
#define MOVE_SPEED 5

typedef struct s_data {
    void *mlx;
    void *win;
    int rect_x;
    int rect_y;
    int keys[4]; // W, A, S, D
} t_data;

int handle_key_press(int keycode, t_data *data)
{
    if (keycode == 119) // W
        data->keys[0] = 1;
    if (keycode == 97)  // A
        data->keys[1] = 1;
    if (keycode == 115) // S
        data->keys[2] = 1;
    if (keycode == 100) // D
        data->keys[3] = 1;
    return (0);
}

int handle_key_release(int keycode, t_data *data)
{
    if (keycode == 119) // W
        data->keys[0] = 0;
    if (keycode == 97)  // A
        data->keys[1] = 0;
    if (keycode == 115) // S
        data->keys[2] = 0;
    if (keycode == 100) // D
        data->keys[3] = 0;
    if (keycode == 65307) // ESC
        exit(0);
    return (0);
}

void draw_rectangle(t_data *data)
{
    int x, y;
    for (y = data->rect_y; y < data->rect_y + RECT_SIZE; y++)
        for (x = data->rect_x; x < data->rect_x + RECT_SIZE; x++)
            if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
                mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFFFF);
}

int update(t_data *data)
{
    // Clear window
    mlx_clear_window(data->mlx, data->win);

    // Update position based on key states
    if (data->keys[0] && data->rect_y > 0) // W
        data->rect_y -= MOVE_SPEED;
    if (data->keys[1] && data->rect_x > 0) // A
        data->rect_x -= MOVE_SPEED;
    if (data->keys[2] && data->rect_y < WINDOW_HEIGHT - RECT_SIZE) // S
        data->rect_y += MOVE_SPEED;
    if (data->keys[3] && data->rect_x < WINDOW_WIDTH - RECT_SIZE) // D
        data->rect_x += MOVE_SPEED;

    // Draw rectangle
    draw_rectangle(data);

    return (0);
}

int main(void)
{
    t_data data;

    // Initialize MLX and window
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "WASD Control");

    // Initialize rectangle position (center)
    data.rect_x = (WINDOW_WIDTH - RECT_SIZE) / 2;
    data.rect_y = (WINDOW_HEIGHT - RECT_SIZE) / 2;

    // Initialize key states
    for (int i = 0; i < 4; i++)
        data.keys[i] = 0;

    // Set up hooks
    mlx_hook(data.win, 2, 1L<<0, handle_key_press, &data); // Key press
    mlx_hook(data.win, 3, 1L<<1, handle_key_release, &data); // Key release
    mlx_loop_hook(data.mlx, update, &data); // Update loop

    // Start MLX loop
    mlx_loop(data.mlx);

    return (0);
}