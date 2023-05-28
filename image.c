/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:59:50 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/27 15:23:39 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void put_img(t_mapinfo *info)
{
    int i;
    int j;
    i = 0;
    while(i < info->height)
    {
        j = 0;
        while(j <= info->width)
        {
            
            mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->space, j * 50, i * 50);
            if(info->map[i][j] == '1')
                mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->wall, j * 50, i * 50);
            if(info->map[i][j] == 'C')
                mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->collectible, j * 50, i * 50);
            if(info->map[i][j] == 'P')
                mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->player, j * 50, i * 50);
            if(info->map[i][j] == 'E')
                mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->exit, j * 50, i * 50);
            j++;
        }
        i++;
    }
    
}