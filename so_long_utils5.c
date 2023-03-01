/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:55:28 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/01 23:39:22 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void right_player(t_long *so_long)
{
    so_long->xp += 1;
    draw_map(so_long);
}
void left_player(t_long *so_long)
{
    so_long->xp -= 1;
    draw_map(so_long);
}
void up_player(t_long *so_long)
{
    so_long->yp -= 1;
    draw_map(so_long);
}
void down_player(t_long *so_long)
{
    so_long->yp += 1;
    draw_map(so_long);
}

int key_handler(int key, t_long *so_long)
{
    if (key == 124 && so_long->maps[so_long->yp][so_long->xp + 1] != '1') 
    {
       right_player(so_long);
       eat_coin(so_long);
    }
    if (key == 123 && so_long->maps[so_long->yp][so_long->xp - 1] != '1') 
       left_player(so_long);
    if (key == 126 && so_long->maps[so_long->yp - 1 ][so_long->xp] != '1') 
       up_player(so_long);
    if (key == 125 && so_long->maps[so_long->yp + 1][so_long->xp] != '1') 
       down_player(so_long);
    if (key == 53)
    {
        write(1, "You Exit The Game\n", 19);
        exit(0);
    }
    return key;
}
