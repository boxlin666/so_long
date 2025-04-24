void render_map(t_game *game)
{
    int x, y;

    for (y = 0; y < game->rows; y++)
    {
        for (x = 0; x < game->cols; x++)
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 64, y * 64);
            else if (game->map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->img_empty, x * 64, y * 64);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * 64, y * 64);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x * 64, y * 64);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 64, y * 64);
        }
    }
}