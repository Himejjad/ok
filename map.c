/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:26:45 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/03 17:27:47 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void chec_pos(t_long *so_long)
{
    int i = 0;
    int j;
    while(so_long->maps[i])
    {
        j = 0;
        while (so_long->maps[i][j])
        {
            if (so_long->maps[i][j] == 'P')
            {
                so_long->yp = i;
                so_long->xp = j;
                return;
            }
            j++;
        }
        i++;
    }
}

void get_stock(t_long  *so_long)
{
    char * dst = get_next_line(so_long->fd);
    if (!dst || so_long->fd < 0)
        error();
    so_long->stock = malloc(1);
    so_long->stock[0] = '\0';
    while(dst)
    {
        so_long->stock = ft_strjoin(so_long->stock, dst);
        free(dst);
        dst = get_next_line(so_long->fd);
    }
    free(dst);
}

void parce_map(t_long  *so_long)
{
        get_stock(so_long);
        so_long->maps = ft_split(so_long->stock, '\n');
        so_long->map_copy = ft_split(so_long->stock, '\n');
        ft_int(so_long);
        check_d_newline(so_long->stock);
        check_wall(so_long);
        write(1,"\033[32m", 5);
        write(1,"VALID\n", 7);
}