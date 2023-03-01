/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 02:51:09 by himejjad          #+#    #+#             */
/*   Updated: 2023/02/28 20:55:19 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void    flood_fill(char **map, int xp, int yp)
{
    if (map[yp][xp] == '1' || map[yp][xp] == '*')
        return;
    map[yp][xp] = '*';
    flood_fill(map , xp + 1, yp);
    flood_fill(map, xp , yp + 1);
    flood_fill(map, xp - 1, yp);
    flood_fill(map, xp , yp - 1);
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

int main(int ac, char **av)
{
    t_long  *so_long;
    so_long = malloc(sizeof(t_long));
    so_long->fd= open (av[1], O_RDONLY);
    if (ac == 2 && check_ber(av[1]))
    {
        parce_map(so_long);
    }
    else
        error();
    put_img(so_long);
}
