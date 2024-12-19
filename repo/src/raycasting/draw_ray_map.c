/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:50:27 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 22:52:34 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_ray_map(t_data *data)
{
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	while (fabs(data->ray_x - data->hit_x) > data->ray_dir_ratio
		|| fabs(data->ray_y - data->hit_y) > data->ray_dir_ratio)
	{
		mlx_put_pixel(data->map_rays, data->ray_x * data->box_size,
			data->ray_y * data->box_size, RAY_COLOR);
		data->ray_x += data->ray_dir_x * data->ray_dir_ratio;
		data->ray_y += data->ray_dir_y * data->ray_dir_ratio;
	}
	mlx_put_pixel(data->map_rays,
		(data->hit_x - 0.05 * data->ray_dir_x) * data->box_size,
		(data->hit_y - 0.05 * data->ray_dir_y) * data->box_size, RAY_COLOR);
}

void	draw_ray_minimap(t_data *data)
{
	printf("les dimensions de la minimap : %d %d\n", data->minimap->width, data->minimap->height);
	data->ray_x = data->pos_x;
	data->ray_y = data->pos_y;
	while (fabs(data->ray_x - data->hit_x) > data->ray_dir_ratio
		|| fabs(data->ray_y - data->hit_y) > data->ray_dir_ratio)
	{
		data->mini_ray_x = (data->ray_x - data->pos_x) / data->mini_step + data->minimap->width / 2;
		data->mini_ray_y = (data->ray_y - data->pos_y) / data->mini_step + data->minimap->width / 2;
		if (data->mini_ray_x < 0 || data->mini_ray_x >= data->minimap->width
			|| data->mini_ray_y < 0 || data->mini_ray_y >= data->minimap->height)
			break;
		mlx_put_pixel(data->minimap, data->mini_ray_x, data->mini_ray_y, RAY_COLOR);
		data->ray_x += data->ray_dir_x * data->ray_dir_ratio;
		data->ray_y += data->ray_dir_y * data->ray_dir_ratio;
	}
}
