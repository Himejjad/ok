/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:55:28 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/03 03:43:52 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 
#include "so_long.h"

void right_player(t_long *so_long)
{
    so_long->xp += 1;
    draw_map(so_long);
    eat_coin(so_long);
     moves(so_long);
}

void left_player(t_long *so_long)
{
    so_long->xp -= 1;
    draw_map(so_long);
    eat_coin(so_long);
     moves(so_long);
}
void up_player(t_long *so_long)
{
    so_long->yp -= 1;
    draw_map(so_long);
    eat_coin(so_long);
}
void down_player(t_long *so_long)
{
    so_long->yp += 1;
    draw_map(so_long);
    eat_coin(so_long);
     moves(so_long);
}

int key_handler(int key, t_long *so_long)
{    
   if ((key == 124 ||key == 2 ) && so_long->maps[so_long->yp][so_long->xp + 1] 
   != '1' && so_long->maps[so_long->yp][so_long->xp + 1] != 'E') 
        right_player(so_long);
    else if ((key == 123 ||key == 0 ) && so_long->maps[so_long->yp][so_long->xp - 1] 
    != '1' && so_long->maps[so_long->yp][so_long->xp - 1] != 'E') 
        left_player(so_long);
    else if ((key == 126 ||key == 13) && so_long->maps[so_long->yp - 1 ][so_long->xp]
     != '1' && so_long->maps[so_long->yp - 1][so_long->xp]!= 'E') 
        up_player(so_long);
    else if ((key == 125 ||key == 1) && so_long->maps[so_long->yp + 1][so_long->xp] != '1' 
    && so_long->maps[so_long->yp + 1][so_long->xp] != 'E' ) 
        down_player(so_long);
    else if (key == 53)
    {
        write(1, "You Exit The Game\n", 19);
        exit(0);
    }
    return key;
}
void moves(t_long *so_long)
{
    check_exit(so_long);
    so_long->move++;
    printf("moves : %d\n",  so_long->move);
}
