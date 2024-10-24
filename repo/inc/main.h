/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:14 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/24 16:47:21 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

# define W_WIDTH 3500 // la largeur de la fenêtre
# define W_HEIGHT 1500 // hauteur de la fenêtre
# define CEIL_COLOR 0x409ec9FF
# define FLOOR_COLOR 0x8B4513FF
# define PATH_MAP "maps/simple.cub"
# define SIZE_BOX 50.0 // la largeur d'une case de la minimap en pixels
# define SIZE_PLAYER (SIZE_BOX / 2) // la largeur du joueur sur la minimap en pixels
# define STEP_MOVE 5.0 // le pas de déplacement du joueur en pixels
# define STEP_VIEW 0.05 // le pas de déplacement de l'angle de vue en radians
# define ROW_START 2 // l'indice de la ligne de départ du joueur
# define COL_START 2 // l'indice de la colonne de départ du joueur
# define ANGLE_START 0 // l'orientation de départ du joueur en radians
# define ANGLE_VIEW (M_PI / 3) // l'angle de vue en radians
# define NB_RAYS 1000 // le nombre de rayons lancés

// typedef struct s_point
// {
// 	unsigned int	x;
// 	unsigned int	y;
// }	t_point;

// typedef struct s_points
// {
// 	double	a_x;
// 	double	a_y;
// 	double	b_x;
// 	double	b_y;
// }	t_points;

// typedef struct s_u_points
// {
// 	unsigned int	a_x;
// 	unsigned int	a_y;
// 	unsigned int	b_x;
// 	unsigned int	b_y;
// }	t_u_points;

typedef struct s_data
{
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*background;
	mlx_image_t	*map_img;
	mlx_image_t	*player;
	mlx_image_t	*rays;
	mlx_image_t	*walls;
	double		x;
	double		y;
	double		angle;
}	t_data;

/* free.c */
void		free_all(t_data *data);
void		perror_exit(char *s, t_data *data);
void		mlx_perror_exit(t_data *data);

/* esc_hook.c */
void		esc_hook(mlx_key_data_t keydata, void *param);

/* main_hook.c */
void		main_hook(void *param);

/* utils.c */
void	fill_image(mlx_image_t *image, unsigned int color);

#endif