int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        return (1);
    game.map = read_map(argv[1], &game);
    if (!game.map || !validate_map(&game)) // Implement validate_map
        return (1);
    init_game(&game);
    render_map(&game);
    setup_hooks(&game);
    mlx_loop(game.mlx);
    return (0);
}