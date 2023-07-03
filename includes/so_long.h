#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
typedef struct s_img {
mlx_image_t			*tile;
} t_img;

typedef struct s_game {
	char			**map_grid;
	size_t			width;
	size_t			height;
	size_t			collectibles;
	size_t			steps;
	size_t			collected;
	size_t			player_x;
	size_t			player_y;
	size_t			exit_x;
	size_t			exit_y;
	mlx_texture_t	*player_up;
	mlx_texture_t	*player_down;
	mlx_texture_t	*player_left;
	mlx_texture_t	*player_right;
	t_img			*img;
	mlx_t			*mlx;
}	t_game;



int main(int ac, char **av);

// error functions

void write_error(char *str);
void map_check(char *map_str);
void empty_map(char *map);
void empty_lines(char *map);
void wrong_content(char *map);
void wrong_shape(char *map);

// initialization

t_game	*game_init(char *map);
t_game	*init_struct(char **map_grid);

// map functions
char *read_map(char *map);
size_t count_rows(char **map_grid);
size_t count_collectibles(t_game *game);
size_t get_position(t_game *game, char axis, char obj);

#endif