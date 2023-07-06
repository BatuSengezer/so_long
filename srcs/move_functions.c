# include "../include/so_long.h"

void	move_hook(mlx_key_data_t keydata, void *input)
{
	t_game	*game;

	game = (t_game *) input;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, 'y', 'w');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, 'y', 's');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'd');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, 'x', 'a');
}

void	move_player(t_game *game, char axis, char dir)
{
	move_select(game, axis, dir);
	load_link(game, dir);
}

void	move_select(t_game *game, char axis, char dir)
{
	if (axis == 'y')
	{
		if (dir == 'w')
			move_up(game);
		else
			move_down(game);
	}
	if (axis == 'x')
	{
		if (dir == 'd')
			move_right(game);
		else
			move_left(game);
	}
}