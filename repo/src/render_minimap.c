/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:48:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/20 18:08:24 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_pixel_minimap(t_data *data)
{
	if (data->xd < 0 || data->yd < 0 || data->xd >= data->map_width
		|| data->yd >= data->map_height)
		data->pixel = MAP_COLOR_BG;
	else if ((data->xd - (int)data->xd) < 0.05
		|| (data->yd - (int)data->yd) < 0.05)
		data->pixel = 0x000000FF;
	else if (data->map[(int)data->xd][(int)data->yd] == '1')
		data->pixel = MAP_COLOR_WALL;
	else
		data->pixel = MAP_COLOR_BG;
}

void rotate_vector_left_90(double *a, double *b, double c, double d)
{
	*a = -d;
	*b = c;
}
void rotate_vector_right_90(double *a, double *b, double c, double d)
{
	*a = d;
	*b = -c;
}

void	render_minimap(t_data *data)
{
	rotate_vector_left_90(&data->mini_dir_x, &data->mini_dir_y, data->dir_x, data->dir_y);
	rotate_vector_left_90(&data->mini_perp_x, &data->mini_perp_y, data->mini_dir_x, data->mini_dir_y);
	data->x = 0;
	while (data->x < data->minimap->width)
	{
		data->y = 0;
		while (data->y < data->minimap->width)
		{
			data->mini_x = (data->x - (double)data->mini_w_2) / data->mini_box_size;
			data->mini_y = (data->y - (double)data->mini_w_2) / data->mini_box_size;
			data->xd = data->pos_x + data->mini_x * data->mini_dir_x + data->mini_y * data->mini_perp_x;
			data->yd = data->pos_y + data->mini_x * data->mini_dir_y + data->mini_y * data->mini_perp_y;
			get_pixel_minimap(data);
			mlx_put_pixel(data->minimap, data->x, data->y, data->pixel);
			data->y++;
		}
		data->x++;
	}
}
// void	render_minimap(t_data *data)
// {
// 	data->mini_dir_x = -data->dir_y;
// 	data->mini_dir_y = data->dir_x;
// 	data->x = 0;
// 	while (data->x < data->minimap->width)
// 	{
// 		data->y = 0;
// 		while (data->y < data->minimap->width)
// 		{
// 			if ((2 * data->x - data->minimap->width) * (2 * data->x - data->minimap->width) + (2 * data->y - data->minimap->width) * (2 * data->y - data->minimap->width) <= data->mini_w_2)
// 			{
// 				data->mini_x = (data->x - data->minimap->width / 2.0) * data->mini_step;
// 				data->mini_y = (data->y - data->minimap->width / 2.0) * data->mini_step;
// 				data->xd = data->pos_x + data->mini_x * data->mini_dir_x + data->mini_y * -data->mini_dir_y;
// 				data->yd = data->pos_y + data->mini_x * data->mini_dir_y + data->mini_y * data->mini_dir_x;
// 				get_pixel_minimap(data);
// 				mlx_put_pixel(data->minimap, data->x, data->y, data->pixel);
// 			}
// 			data->y++;
// 		}
// 		data->x++;
// 	}
// }
