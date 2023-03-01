/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:31:38 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/01 23:37:34 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ground(t_long *so_long)
{
    int i;
    int j;
    i = 0;
    while (so_long->maps[i])
    {
        j = 0;
        while (so_long->maps[i][j])
        {
            put_ground(so_long, so_long->s_win, i * 50, j * 50);
                j++;
        }
        i++;
    }
}

void draw_map(t_long *so_long)
{
    int i;
    int j;
    i = 0;
    ground(so_long);
    while (so_long->maps[i])
    {
        j = 0;
        while (so_long->maps[i][j])
        {
            if (so_long->maps[i][j] == '1')
                put_wall(so_long, so_long->s_win, i * 50, j * 50);
            else if (so_long->maps[i][j] == 'E')
                put_dor(so_long, so_long->s_win, i * 50, j * 50);
            else if (so_long->maps[i][j] == 'C')
                put_collect(so_long, so_long->s_win, i * 50, j * 50);
                j++;
        }
        i++;
    }
    put_player(so_long, so_long->s_win);
}

