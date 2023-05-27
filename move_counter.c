/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:01:37 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/26 19:47:42 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_counter(t_mapinfo *info)
{
    if(info->collectible_count >= 0)
    {
        info->move_count += 1;
        ft_putnbr_fd(info->move_count, 1);
        ft_putchar_fd('\n', 1);
    }
}