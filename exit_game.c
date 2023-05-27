/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:28:51 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/26 23:57:33 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int exit_game(t_mapinfo *info)
{
    free_double_pointer(info->map);
    printf("helo\n");
    free(info);
    // (void)info;
    exit(0);
    // return 1;
}