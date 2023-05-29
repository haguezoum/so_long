/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:02:14 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/29 01:17:23 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_real_time_img(t_mapinfo *info, void *object);

void	left(t_mapinfo *info)
{
	if (info->p_pos_x > 1 && info->map[info->p_pos_y][info->p_pos_x - 1] != '1')
	{
		if (info->map[info->p_pos_y][info->p_pos_x - 1] == 'C')
		{
			info->ccnt--;
			info->map[info->p_pos_y][info->p_pos_x - 1] = '0';
		}
		if ((info->map[info->p_pos_y][info->p_pos_x] == 'E')
			&& (info->ccnt > 0))
			info->map[info->p_pos_y][info->p_pos_x] = 'E';
		else
			info->map[info->p_pos_y][info->p_pos_x] = '0';
		info->p_pos_x -= 1;
		if ((info->map[info->p_pos_y][info->p_pos_x] == 'E')
			&& (info->ccnt > 0))
		{
			put_real_time_img(info, info->space);
			info->map[info->p_pos_y][info->p_pos_x] = 'E';
		}
		put_real_time_img(info, info->player);
		move_counter(info);
		if (info->map[info->p_pos_y][info->p_pos_x] == 'E' && (info->ccnt == 0))
			exit_game(info);
	}
}

void	right(t_mapinfo *info)
{
	if (info->p_pos_x < info->width - 1
		&& info->map[info->p_pos_y][info->p_pos_x + 1] != '1')
	{
		if (info->map[info->p_pos_y][info->p_pos_x + 1] == 'C')
		{
			info->ccnt--;
			info->map[info->p_pos_y][info->p_pos_x + 1] = '0';
		}
		if ((info->map[info->p_pos_y][info->p_pos_x] == 'E')
			&& (info->ccnt > 0))
			info->map[info->p_pos_y][info->p_pos_x] = 'E';
		else
			info->map[info->p_pos_y][info->p_pos_x] = '0';
		info->p_pos_x += 1;
		if ((info->map[info->p_pos_y][info->p_pos_x] == 'E')
			&& (info->ccnt > 0))
		{
			put_real_time_img(info, info->space);
			info->map[info->p_pos_y][info->p_pos_x] = 'E';
		}
		put_real_time_img(info, info->player);
		move_counter(info);
		if (info->map[info->p_pos_y][info->p_pos_x] == 'E' && (info->ccnt == 0))
			exit_game(info);
	}
}

void	top(t_mapinfo *info)
{
	if (info->p_pos_y > 1 && info->map[info->p_pos_y - 1][info->p_pos_x] != '1')
	{
		if (info->map[info->p_pos_y - 1][info->p_pos_x] == 'C')
		{
			info->ccnt --;
			info->map[info->p_pos_y - 1][info->p_pos_x] = '0';
		}
		if ((info->map[info->p_pos_y][info->p_pos_x] == 'E')
			&& (info->ccnt > 0))
			info->map[info->p_pos_y][info->p_pos_x] = 'E';
		else
			info->map[info->p_pos_y][info->p_pos_x] = '0';
		info->p_pos_y -= 1;
		if ((info->map[info->p_pos_y][info->p_pos_x] == 'E')
			&& (info->ccnt > 0))
		{
			put_real_time_img(info, info->space);
			info->map[info->p_pos_y][info->p_pos_x] = 'E';
		}
		put_real_time_img(info, info->player);
		move_counter(info);
		if (info->map[info->p_pos_y][info->p_pos_x] == 'E' && (info->ccnt == 0))
			exit_game(info);
	}
}

void	buttom(t_mapinfo *info)
{
	if (info->p_pos_y < info->height - 2
		&& info->map[info->p_pos_y + 1][info->p_pos_x] != '1')
	{
		if (info->map[info->p_pos_y + 1][info->p_pos_x] == 'C')
		{
			info->ccnt --;
			info->map[info->p_pos_y + 1][info->p_pos_x] = '0';
		}
		if ((info->map[info->p_pos_y][info->p_pos_x] == 'E')
			&& (info->ccnt > 0))
			info->map[info->p_pos_y][info->p_pos_x] = 'E';
		else
			info->map[info->p_pos_y][info->p_pos_x] = '0';
		info->p_pos_y += 1;
		if ((info->map[info->p_pos_y][info->p_pos_x] == 'E')
			&& (info->ccnt > 0))
		{
			put_real_time_img(info, info->space);
			info->map[info->p_pos_y][info->p_pos_x] = 'E';
		}
		put_real_time_img(info, info->player);
		move_counter(info);
		if (info->map[info->p_pos_y][info->p_pos_x] == 'E' && (info->ccnt == 0))
			exit_game(info);
	}
}

void	put_real_time_img(t_mapinfo *info, void *object)
{
	put_img(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, object,
		info->p_pos_x * 50, info->p_pos_y * 50);
}
