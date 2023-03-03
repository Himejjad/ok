/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:27:13 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/03 17:07:08 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"


void map_check(t_long *so_long)
{
    int first_line  = so_long->width;
    int i;

    i = 1;
    while (i < so_long->hight)
    {
        if (ft_strlen (so_long->maps[i]) != first_line)
            error();
        i++;
    }
    
}

int check_ber(char *file)
{
    int len = ft_strlen(file);
    int i = 0;
    if (!file)
        error();
    while (file[i] && ft_strcmp(file + (len - 4), ".ber") == 0)
        i++;
    if (len > 4 && ft_strcmp(file + (len - (i - 4)), ".ber") == 0)
        return (1);
     else 
        return (0);
}

void check_wall(t_long *so_long)
{
    check_wall2(so_long);
    chec_pos(so_long);
    flood_fill(so_long->map_copy, so_long->xp, so_long->yp);
    int l = 0;
    while (so_long->map_copy[l])
    {
        int k = 0;
        while (so_long->map_copy[l][k])
        {
            if (so_long->map_copy[l][k] == 'E'
                || so_long->map_copy[l][k] == 'C')
                error();
            k++;
        }
        l++;
    }
}

void check_d_newline(char *map)
{
    int i;

    i = 0;
    if(map[0] == '1')
    {
        while (map[i])
        {
            if (map[i] == '\n' && map[i + 1] == '\n')
               error();
            i++;
        }
    }
}

void  check_wall2(t_long *so_long)
{
    int i;
    int j;

    i = 0;
    j = 0;
    map_check(so_long);
    check_char(so_long);
    while(so_long->maps[i][j])
    {
        if (so_long->maps[i][j] != '1' || so_long->maps[so_long->hight - 1][j] != '1')
            error();
        
        j++;
    }
    i++;
    while(i < so_long->hight)
    {
        if(so_long->maps[i][0] != '1' || so_long->maps[i][so_long->width - 1] != '1')
            error();
        i++;
    }
}