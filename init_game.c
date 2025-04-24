#include "mlx.h"

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->cols * 64, game->rows * 64, "so_long");
    // Load images (assuming 64x64 pixel sprites)
    game->img_player = mlx_xpm_file_to_image(game->mlx, "player.xpm", &(int){64}, &(int){64});
    game->img_wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &(int){64}, &(int){64});
    game->img_collectible = mlx_xpm_file_to_image(game->mlx, "collectible.xpm", &(int){64}, &(int){64});
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "exit.xpm", &(int){64}, &(int){64});
    game->img_empty = mlx_xpm_file_to_image(game->mlx, "empty.xpm", &(int){64}, &(int){64});
}