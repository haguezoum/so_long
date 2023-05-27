/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:02:14 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/26 21:41:23 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void left(t_mapinfo *info)
{
    if(info->player_pos_x > 1 && info->map[info->player_pos_y][info->player_pos_x - 1] != '1') 
    {
        if(info->map[info->player_pos_y][info->player_pos_x - 1] == 'C')
        {
            info->collectible_count --;
            info->map[info->player_pos_y][info->player_pos_x - 1] = '0';
        } 
        if((info->map[info->player_pos_y][info->player_pos_x ] == 'E') && (info->collectible_count > 0))
            info->map[info->player_pos_y][info->player_pos_x] = 'E';
        else
            info->map[info->player_pos_y][info->player_pos_x] = '0';
        info->player_pos_x -= 1;
        if((info->map[info->player_pos_y][info->player_pos_x ] == 'E') && (info->collectible_count > 0))
        {
            mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->space, info->player_pos_x * 50, info->player_pos_y * 50);
            info->map[info->player_pos_y][info->player_pos_x] = 'E';
        }
        put_img(info);
        mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->player, info->player_pos_x * 50, info->player_pos_y * 50);
        move_counter(info);
        if(info->map[info->player_pos_y][info->player_pos_x] == 'E' && (info->collectible_count == 0))
            exit_game(info);
    }
}

void right(t_mapinfo *info)
{ 
    if(info->player_pos_x < info->width - 1 && info->map[info->player_pos_y][info->player_pos_x + 1] != '1')
    {
        if(info->map[info->player_pos_y][info->player_pos_x + 1] == 'C')
        {
            info->collectible_count --;
            info->map[info->player_pos_y][info->player_pos_x + 1] = '0';
        }
        if((info->map[info->player_pos_y][info->player_pos_x ] == 'E') && (info->collectible_count > 0))
            info->map[info->player_pos_y][info->player_pos_x] = 'E';
        else
            info->map[info->player_pos_y][info->player_pos_x] = '0';
        info->player_pos_x += 1;
        if((info->map[info->player_pos_y][info->player_pos_x ] == 'E') && (info->collectible_count > 0))
        {
            mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->space, info->player_pos_x * 50, info->player_pos_y * 50);
            info->map[info->player_pos_y][info->player_pos_x] = 'E';
        }
        put_img(info);
        mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->player, info->player_pos_x * 50, info->player_pos_y * 50);
        move_counter(info);
        if(info->map[info->player_pos_y][info->player_pos_x] == 'E' && (info->collectible_count == 0))
            exit_game(info);
    }
}

void top(t_mapinfo *info)
{
    if(info->player_pos_y > 1 && info->map[info->player_pos_y - 1][info->player_pos_x] != '1')
    {
        if(info->map[info->player_pos_y - 1][info->player_pos_x] == 'C')
        {
            info->collectible_count --;
            info->map[info->player_pos_y - 1][info->player_pos_x] = '0';
        }  
        if((info->map[info->player_pos_y][info->player_pos_x ] == 'E') && (info->collectible_count > 0))
            info->map[info->player_pos_y][info->player_pos_x] = 'E';
        else
            info->map[info->player_pos_y][info->player_pos_x] = '0';
        info->player_pos_y -= 1;
        if((info->map[info->player_pos_y][info->player_pos_x ] == 'E') && (info->collectible_count > 0))
        {
            mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->space, info->player_pos_x * 50, info->player_pos_y * 50);
            info->map[info->player_pos_y][info->player_pos_x] = 'E';
        }
        put_img(info);
        mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->player, info->player_pos_x * 50, info->player_pos_y * 50);
        move_counter(info);
        if(info->map[info->player_pos_y][info->player_pos_x] == 'E' && (info->collectible_count == 0))
            exit_game(info);
    }
}

void buttom(t_mapinfo *info)
{
    if(info->player_pos_y < info->height - 2 && info->map[info->player_pos_y + 1][info->player_pos_x] != '1')
    {
        if(info->map[info->player_pos_y + 1][info->player_pos_x] == 'C')
        {
            info->collectible_count --;
            info->map[info->player_pos_y + 1][info->player_pos_x] = '0';
        }
        if((info->map[info->player_pos_y][info->player_pos_x ] == 'E') && (info->collectible_count > 0))
            info->map[info->player_pos_y][info->player_pos_x] = 'E';
        else
            info->map[info->player_pos_y][info->player_pos_x] = '0';
        info->player_pos_y += 1;
        if((info->map[info->player_pos_y][info->player_pos_x ] == 'E') && (info->collectible_count > 0))
        {
            mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->space, info->player_pos_x * 50, info->player_pos_y * 50);
            info->map[info->player_pos_y][info->player_pos_x] = 'E';
        }
        put_img(info);
        mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->player, info->player_pos_x * 50, info->player_pos_y * 50);
        move_counter(info);
        if(info->map[info->player_pos_y][info->player_pos_x] == 'E' && (info->collectible_count == 0))
           exit_game(info);
    }
}

void playe_pos(t_mapinfo *info)
{
    int i = -1;
    int j;
    while(++i < info->height)
    {
        j = -1;
        while(++j <= info->width)
        {
            if(info->map[i][j] == 'P')
            {
                info->player_pos_x = j;
                info->player_pos_y = i;
                break;
            }
        }
    }
}