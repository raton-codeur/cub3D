/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:02:39 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 11:05:22 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	iterate_dda(t_data *data)
{
	data->hit = 0;
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->i += data->step_i;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->j += data->step_j;
			data->side = 1;
		}
		if (data->map[data->i][data->j] == '1'
			|| data->map[data->i][data->j] == 'D')
			data->hit = 1;
	}
}

static void	get_texture_infos(t_data *data)
{
	if (data->side == 1 && data->step_j == -1)
	{
		data->tex = data->north;
		data->tex_x = data->tex->width * (data->hit_x - (int)data->hit_x);
	}
	else if (data->side == 1)
	{
		data->tex = data->south;
		data->tex_x = data->tex->width * (1 - (data->hit_x - (int)data->hit_x));
	}
	else if (data->side == 0 && data->step_i == -1)
	{
		data->tex = data->west;
		data->tex_x = data->tex->width * (1 - (data->hit_y - (int)data->hit_y));
	}
	else
	{
		data->tex = data->east;
		data->tex_x = data->tex->width * (data->hit_y - (int)data->hit_y);
	}
}

static void	get_dda_results(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = data->side_dist_x - data->delta_dist_x;
	else
		data->perp_wall_dist = data->side_dist_y - data->delta_dist_y;
	data->hit_x = data->pos_x + data->ray_dir_x * data->perp_wall_dist;
	data->hit_y = data->pos_y + data->ray_dir_y * data->perp_wall_dist;
	get_texture_infos(data);
	data->wall_height = data->w_height / data->perp_wall_dist;
}

void	dda(t_data *data)
{
	data->x = 0;
	while (data->x < data->w_width)
	{
		init_dda(data);
		iterate_dda(data);
		get_dda_results(data);
		render_for_x(data);
		data->x++;
	}
}
