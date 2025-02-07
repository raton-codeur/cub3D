/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:18:34 by qhauuy            #+#    #+#             */
/*   Updated: 2024/12/21 16:43:56 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "main.h"

/* main_hook.c */
void		main_hook(void *param);

/* key_hook.c */
void		key_hook(mlx_key_data_t keydata, void *param);

/* move.c */
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

/* rotate.c */
void		rotate_x(t_data *data, double step);

/* rotate_bonus.c */
void		rotate_y(t_data *data, int step);

/* set_depth.c */
void		set_depth(t_data *data);

#endif