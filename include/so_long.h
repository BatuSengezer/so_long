/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:44:49 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/09 22:45:15 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>

# define PIXELS 64

typedef struct s_img {
	mlx_image_t			*bush;
	mlx_image_t			*grass;
	mlx_image_t			*collectible;
	mlx_image_t			*player;
	mlx_image_t			*exit_closed;
	mlx_image_t			*exit_open;
	mlx_image_t			*enemy;
	mlx_image_t			*print_moves;
	mlx_image_t			*count_moves;
	mlx_image_t			*collectibles_count;
}	t_img;

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

typedef struct s_var {
	int				ran_x;
	int				ran_y;
	int				*x;
	int				*y;
	int				index_x;
	int				index_y;
}	t_tmp;

int		main(int ac, char **av);

// error functions

void	write_error(char *str);
void	map_check(char *map_str);
void	empty_map(char *map);
void	empty_lines(char *map);
void	wrong_content(char *map);
void	wrong_shape(char *map);
void	wrong_wall(char *map);
void	wall_check_horizontal(char *map);
void	wall_check_vertical(char *map);
void	check_file_extension(char *file_name_str);

// initialization

t_game	*init_game(char *map);
t_game	*init_game_struct(char **map_grid);
t_img	*init_img_struct(mlx_t *mlx);

// map functions

char	*read_map(char *map);
size_t	count_rows(char **map_grid);
size_t	count_collectibles(t_game *game);
size_t	get_position(t_game *game, char axis, char obj);
void	flood_fill(t_game *game);
int		path_check(t_game *tmp, size_t y, size_t x);
void	free_grid(char **grid, size_t grid_height);

// image functions
t_img	*load_grass_texture(mlx_t *mlx, t_img *img);
t_img	*load_bush_texture(mlx_t *mlx, t_img *img);
t_img	*load_collectible_texture(mlx_t *mlx, t_img *img);
t_img	*load_exit_closed(mlx_t *mlx, t_img	*img);
t_img	*load_exit_open(mlx_t *mlx, t_img *img);
t_img	*load_enemy_texture(mlx_t *mlx, t_img *img);
t_img	*load_player_texture(mlx_t *mlx, t_img *img);
void	fill_background(t_game *game);
void	select_image(t_game *game, size_t y, size_t x);
void	render_map(t_game *game);
void	load_player_textures(t_game *game);
// void		load_player(t_game *game, char dir);
void	screen_str(t_game *game);
void	print_moves(t_game *game);
void	print_collectibles(t_game *game);

// move functions

void	move_hook(mlx_key_data_t keydata, void *tmp);
void	move_player(t_game *game, char dir);
t_game	*move_up(t_game *game);
t_game	*move_down(t_game *game);
t_game	*move_left(t_game *game);
t_game	*move_right(t_game *game);
void	pick_collectibles(t_game *game, int y, int x);
void	win_check(t_game *game);
void	enemy_hook(void *tmp);
void	move_enemies(const t_game *game, int count);
void	kill_check(const t_game *game);

#endif
