/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:28:51 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/28 17:20:04 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_mapinfo *info)
{
	mlx_destroy_image(info->mlx_ptr, info->wall);
	mlx_destroy_image(info->mlx_ptr, info->space);
	mlx_destroy_image(info->mlx_ptr, info->player);
	mlx_destroy_image(info->mlx_ptr, info->exit);
	mlx_destroy_image(info->mlx_ptr, info->collectible);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	free_double_pointer(info->map);
	exit(0);
}
