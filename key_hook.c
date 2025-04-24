int key_hook(int keycode, t_game *game)
{
    int new_x = game->player_x;
    int new_y = game->player_y;

    if (keycode == 13 || keycode == 126) // W or Up
        new_y--;
    else if (keycode == 1 || keycode == 125) // S or Down
        new_y++;
    else if (keycode == 0 || keycode == 123) // A or Left
        new_x--;
    else if (keycode == 2 || keycode == 124) // D or Right
        new_x++;
    else if (keycode == 53) // ESC
        exit(0);

    // Check if move is valid
    if (new_x >= 0 && new_x < game->cols && new_y >= 0 && new_y < game->rows && game->map[new_y][new_x] != '1')
    {
        if (game->map[new_y][new_x] == 'C')
            game->collectibles--;
        if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
            exit(0); // Win condition
        game->map[game->player_y][game->player_x] = '0';
        game->map[new_y][new_x] = 'P';
        game->player_x = new_x;
        game->player_y = new_y;
        game->moves++;
        printf("Moves: %d\n", game->moves);
        render_map(game);
    }
    return (0);
}

void setup_hooks(t_game *game)
{
    mlx_hook(game->win, 2, 1L << 0, key_hook, game);
    mlx_hook(game->win, 17, 0, (int (*)())exit, 0); // Close window
}