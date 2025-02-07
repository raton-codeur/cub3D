/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:17:31 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/19 16:22:37 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		if (data->depth_config == 1)
			data->depth_config = 0;
		else
			data->depth_config = 1;
		set_depth(data);
	}
	if (keydata.key == MLX_KEY_N && keydata.action == MLX_PRESS)
	{
		if (data->depth_config == 2)
			data->depth_config = 0;
		else
			data->depth_config = 2;
		set_depth(data);
	}
}
