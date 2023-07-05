
# include "../include/so_long.h"

t_img	*load_grass_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./sprites/Grass.png");
	if (!grass)
		write_error("Error while loading png");
	img->grass = mlx_texture_to_image(mlx, grass);
	if (!img->grass)
		write_error("Error during texture to image");
	mlx_delete_texture(grass);
	return (img);
}

t_img	*load_bush_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*bush;

	bush = mlx_load_png("./sprites/Bush.png");
	if (!bush)
		write_error("Error while loading png");
	img->bush = mlx_texture_to_image(mlx, bush);
	if (!img->bush)
		write_error("Error during texture to image");
	mlx_delete_texture (bush);
	return (img);
}

t_img	*load_collectible_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*collectible;

	collectible = mlx_load_png("./sprites/Collectible.png");
	if (!collectible)
		write_error("Error while loading png");
	img->collectible = mlx_texture_to_image(mlx, collectible);
	if (!img->collectible)
		write_error("Error during texture to image");
	mlx_delete_texture(collectible);
	return (img);
}

t_img	*load_exit_closed(mlx_t *mlx, t_img	*img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./sprites/Exit_Closed.png");
	if (!exit)
		write_error("Error while loading png");
	img->exit_closed = mlx_texture_to_image(mlx, exit);
	if (!img->exit_closed)
		write_error("Error during texture to image");
	mlx_delete_texture(exit);
	return (img);
}

t_img	*load_exit_open(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./sprites/Exit_Open.png");
	if (!exit)
		write_error("Error while loading png");
	img->exit_open = mlx_texture_to_image(mlx, exit);
	if (!img->exit_open)
		write_error("Error during texture to image");
	mlx_delete_texture(exit);
	return (img);
}
