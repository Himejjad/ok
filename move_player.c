/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:31:38 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/01 21:42:46 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void up_player(t_win *s_win)
// {
    
// }

void draw_map(t_long *so_long)
{
    int i;
    int j;
    i = 0;
    while (so_long->maps[i])
    {
        j = 0;
        while (so_long->maps[i][j])
        {
            if (so_long->maps[i][j] == '1')
                put_wall(so_long, so_long->s_win, i, j);
            else if (so_long->maps[i][j] == '0')
                put_ground(so_long, so_long->s_win, i, j);
            else if (so_long->maps[i][j] == 'E')
                put_dor(so_long, so_long->s_win, i, j);
            else if (so_long->maps[i][j] == 'C')
                put_collect(so_long, so_long->s_win, i, j);
        }
    }
    put_player(so_long, so_long->s_win);
}

void up_player(t_long *so_long)
{
    // t_win *s_win = ft_initial(so_long);

    //put_player(so_long, s_win, s_win->i, s_win->j);
    //s_win->j += 50;
    printf("====>%d\n", so_long->xp);
    so_long->xp += 50;
    printf("/////>%d\n", so_long->xp);
    draw_map(so_long);

}