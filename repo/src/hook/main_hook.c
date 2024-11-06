/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:39:57 by qhauuy            #+#    #+#             */
/*   Updated: 2024/10/24 19:09:110 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	erase_image(mlx_image_t *image)
{
	ft_bzero(image->pixels, image->width * image->height * sizeof(uint32_t));
}

void	check_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)) // up
	{
		data->pos_x += STEP_MOVE * data->dir_x;
		data->pos_y += STEP_MOVE * data->dir_y;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)) // down
	{
		data->pos_x -= STEP_MOVE * data->dir_x;
		data->pos_y -= STEP_MOVE * data->dir_y;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)) // left
	{
		data->pos_x += STEP_MOVE * data->dir_y;
		data->pos_y -= STEP_MOVE * data->dir_x;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)) // right
	{
		data->pos_x -= STEP_MOVE * data->dir_y;
		data->pos_y += STEP_MOVE * data->dir_x;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)) // rotate right
	{
		data->dir_x = data->dir_x * cos(STEP_VIEW) - data->dir_y * sin(STEP_VIEW);
		data->dir_y = data->dir_x * sin(STEP_VIEW) + data->dir_y * cos(STEP_VIEW);
		data->plane_x = data->plane_x * cos(STEP_VIEW) - data->plane_y * sin(STEP_VIEW);
		data->plane_y = data->plane_x * sin(STEP_VIEW) + data->plane_y * cos(STEP_VIEW);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT)) // rotate left
	{
		data->dir_x = data->dir_x * cos(-STEP_VIEW) - data->dir_y * sin(-STEP_VIEW);
		data->dir_y = data->dir_x * sin(-STEP_VIEW) + data->dir_y * cos(-STEP_VIEW);
		data->plane_x = data->plane_x * cos(-STEP_VIEW) - data->plane_y * sin(-STEP_VIEW);
		data->plane_y = data->plane_x * sin(-STEP_VIEW) + data->plane_y * cos(-STEP_VIEW);
	}
	data->player->instances[0].x = data->pos_x - SIZE_PLAYER / 2;
	data->player->instances[0].y = data->pos_y - SIZE_PLAYER / 2;
}

void cast_ray(t_data *data)
{
	double ray_dir_x;
	double ray_dir_y;
	double delta_dist_x;
	double delta_dist_y;
	int map_x;
	int map_y;
	double side_dist_x;
	double side_dist_y;
	double perp_wall_dist;
	int step_x;
	int step_y;
	int hit;
	int side;

	ray_dir_x = data->dir_x + data->plane_x;
	ray_dir_y = data->dir_y + data->plane_y;
	delta_dist_x = fabs(1 / ray_dir_x);
	delta_dist_y = fabs(1 / ray_dir_y);
	map_x = data->pos_x / SIZE_BOX;
	map_y = data->pos_y / SIZE_BOX;
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (data->pos_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - data->pos_x) * delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (data->pos_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - data->pos_y) * delta_dist_y;
	}
	hit = 0;
	while (hit == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (data->map[map_x][map_y] == 1)
			hit = 1;
	}
	if (side == 0)
		perp_wall_dist = (map_x - data->pos_x + (1 - step_x) / 2) / ray_dir_x;
	else
		perp_wall_dist = (map_y - data->pos_y + (1 - step_y) / 2) / ray_dir_y;
	printf("perp_wall_dist = %f\n", perp_wall_dist);
}

void	main_hook(void *param)
{
	t_data	*data;

	data = param;
	erase_image(data->rays);
	erase_image(data->walls);
	check_keys(data);
	cast_ray(data);	
}
