#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

typedef struct s_game
{
    char **map;
    int rows;
    int cols;
    int player_x;
    int player_y;
    int collectibles;
    int moves;
    void *mlx;
    void *win;
    void *img_player;
    void *img_wall;
    void *img_collectible;
    void *img_exit;
    void *img_empty;
} t_game;

char **read_map(char *filename, t_game *game)
{
    int fd = open(filename, O_RDONLY);
    char *line;
    char **map;
    int i = 0;

    if (fd < 0)
        return (NULL);
    game->rows = 0;
    while ((line = get_next_line(fd)))
        game->rows++;
    close(fd);
    map = malloc(sizeof(char *) * (game->rows + 1));
    fd = open(filename, O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        map[i] = line;
        if (i == 0)
            game->cols = strlen(line) - 1; // Exclude newline
        i++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}