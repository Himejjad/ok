/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:31:38 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/03 17:30:31 by himejjad         ###   ########.fr       */
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
            if (so_long->maps[i][j] != 'x')
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

void put_img(t_long *so_long)
{
    so_long->s_win = ft_initial(so_long);
    so_long->s_win->win = mlx_new_window(so_long->s_win->mlx, so_long->s_win->x, so_long->s_win->y, "soo_long");
    draw_map(so_long);
    mlx_key_hook(so_long->s_win->win, key_handler, so_long);
    mlx_loop(so_long->s_win->mlx);
} 
