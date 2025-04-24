#include "mlx.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define RECT_SIZE 50

typedef struct s_data {
    void    *mlx;
    void    *win;
    int     x;
    int     y;
} t_data;

// 绘制矩形的函数
void draw_rectangle(t_data *data)
{
    int i, j;
    int color = 0x00FF00;  // 绿色矩形

    // 使用 mlx_pixel_put 绘制矩形
    for (i = data->x; i < data->x + RECT_SIZE; i++)
    {
        for (j = data->y; j < data->y + RECT_SIZE; j++)
        {
            mlx_pixel_put(data->mlx, data->win, i, j, color);
        }
    }
}

int handle_key(int key, t_data *data)
{
    if (key == 65307) // ESC 键退出
        mlx_destroy_window(data->mlx, data->win);
    else if (key == 119) // 'W' 键向上移动
        data->y -= 10;
    else if (key == 97)  // 'A' 键向左移动
        data->x -= 10;
    else if (key == 115) // 'S' 键向下移动
        data->y += 10;
    else if (key == 100) // 'D' 键向右移动
        data->x += 10;

    mlx_clear_window(data->mlx, data->win);  // 清空窗口
    draw_rectangle(data);  // 绘制矩形
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Move Rectangle");
    data.x = WIN_WIDTH / 2 - RECT_SIZE / 2;  // 初始 X 位置
    data.y = WIN_HEIGHT / 2 - RECT_SIZE / 2; // 初始 Y 位置

    mlx_key_hook(data.win, handle_key, &data);  // 监听键盘事件
    mlx_loop(data.mlx);  // 启动事件循环

    return (0);
}
