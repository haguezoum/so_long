/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:48:36 by haguezou          #+#    #+#             */
/*   Updated: 2023/05/27 23:35:17 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int  check_elemts(t_mapinfo *info)
{
    if(info->collectible_count < 1)     
    {
        free_double_pointer(info->map);
        free(info);
        error("The map must contain 1 Collectible at least !\n");
    }
    else if(info->player_count < 1)
    {
        free_double_pointer(info->map);
        free(info);
        error("The map must contain 1 Player at least !\n");
    }   
    else if(info->exit_count < 1 || info->exit_count > 1)
    {
        free_double_pointer(info->map);
        free(info);
        error("The map must contain 1 Exit!\n");
    }
    return (0);
}
void count_elemts(t_mapinfo *info)
{
    int i;
    int j;

    i = -1;
    while (++i < info->height)
    {   
        j = -1;
        while (++j <= info->width)
        {
            if(info->map[i][j] == 'C')
                info->collectible_count += 1;
            if(info->map[i][j] == '0')
                info->space_count += 1;
            if(info->map[i][j] == 'E')
                info->exit_count += 1;
            if(info->map[i][j] == 'P')
                info->player_count += 1;
        }
    } 
    check_elemts(info);
}
void check_equale_size_line(t_mapinfo *info)
{
    int i;
    
    i = -1;
    if(info->width > 51 || info->height > 28)
    {
        free_double_pointer(info->map);
        free(info);
        error("Out of window limits !\n");
    }
    while (++i < info->height)
    {
        if((int)ft_strlen(info->map[i])-1 != info->width - 1)
        {
            free_double_pointer(info->map);
            free(info);
            error("Not equale border size !\n");
        }
    }    
} 
void check_for_valid_border(t_mapinfo *info)
{ 
    int i;
    
    i = -1;
    while (++i <= (info->width - 1))
        if((info->map[0][i] != '1' || info->map[info->height - 1][i] != '1'))
        {
            free_double_pointer(info->map);
            free(info);
            error("Invalid map ! \n(side Borders not 1 or empty line)");
        }
    i = -1;
    // || info->map[i][0] == '\n' || info->map[i][0] == '\0'
    while (++i <= (info->height - 1))
        if(info->map[i][0] != '1' || info->map[i][info->width - 1] != '1' )
        {
            free_double_pointer(info->map);
            free(info);
            error("Invalid map ! \n(side Borders not 1)");
        }       
}
void read_map(t_mapinfo *info)
{
    int fd;
    char *line = NULL;
    char *tofree = NULL;
    int i;
    i = 0;
    fd = open(info->map_name, O_RDONLY);
    line = ft_strdup("");
    // tofree = ft_strdup("");
    while(1)
    {
        tofree = get_next_line(fd);
        if(!tofree)
            break;
        line = ft_strjoinsolong(line,tofree);
        free(tofree);
        // free(line);
        info->height += 1;
    }
    // while(1){}
    info->map = ft_split(line, '\n');
    free(tofree);
    free(line);
    close(fd);
    // while(1){}
    // - - - - - -  - - - - - - - - - - 
    
    // while(1){};
    // while(1);
    // info->height = i;
    // close(fd);
    // fd = open(info->map_name, O_RDONLY);
    // while(i > 0)
    // {
    //     tmp = get_next_line(fd);
    //     if (tmp[0] == '\n' || tmp[0] == '\0')
    //     {
    //         free(line);
    //         free(tmp);
    //         free(info);
    //         error("Invalid MAP !");
    //     }
    //     tofree = line;
    //     line = ft_strjoinsolong(line, tmp);
    //     free(tofree);
    //     free(tmp);
    //     i--;
    // }
    // close(fd);
    // printf("%d,%s\n",info->height,line);
    // return (db_p);
}