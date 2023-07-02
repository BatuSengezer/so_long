#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

typedef struct s_img {
mlx_image_t			*tile;
} t_img;

int main(int ac, char **av);

// error check
void write_error(char *str);

// initialization


#endif