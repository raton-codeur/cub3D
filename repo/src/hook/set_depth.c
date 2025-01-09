/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_depth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakgyver <hakgyver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:49:14 by qhauuy            #+#    #+#             */
/*   Updated: 2025/01/09 10:11:07 by hakgyver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	set_depth(t_data *data)
{
	if (data->depth_config == 1)
	{
		mlx_set_instance_depth(&data->minimap_player->instances[0], -1);
		mlx_set_instance_depth(&data->minimap_rays->instances[0], -1);
		mlx_set_instance_depth(&data->minimap->instances[0], -1);
		mlx_set_instance_depth(&data->minimap_bg->instances[0], -1);
		mlx_set_instance_depth(&data->player_map->instances[0], 4);
		mlx_set_instance_depth(&data->rays_map->instances[0], 3);
		mlx_set_instance_depth(&data->map_img->instances[0], 2);
	}
	else if (data->depth_config == 2)
	{
		mlx_set_instance_depth(&data->minimap_player->instances[0], 5);
		mlx_set_instance_depth(&data->minimap_rays->instances[0], 4);
		mlx_set_instance_depth(&data->minimap->instances[0], 3);
		mlx_set_instance_depth(&data->minimap_bg->instances[0], 2);
		mlx_set_instance_depth(&data->map_img->instances[0], -1);
		mlx_set_instance_depth(&data->rays_map->instances[0], -1);
		mlx_set_instance_depth(&data->player_map->instances[0], -1);
	}
	else
	{
		mlx_set_instance_depth(&data->minimap_player->instances[0], -1);
		mlx_set_instance_depth(&data->minimap_rays->instances[0], -1);
		mlx_set_instance_depth(&data->minimap->instances[0], -1);
		mlx_set_instance_depth(&data->minimap_bg->instances[0], -1);
		mlx_set_instance_depth(&data->map_img->instances[0], -1);
		mlx_set_instance_depth(&data->player_map->instances[0], -1);
		mlx_set_instance_depth(&data->rays_map->instances[0], -1);
	}
}
