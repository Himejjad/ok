/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:55:28 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/02 02:03:21 by himejjad         ###   ########.fr       */
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
    if (key == 124) 
    {
        check_exit_wall(so_long);
       right_player(so_long);
       eat_coin(so_long);
    }
    if (key == 123) 
    {
        check_exit_wall(so_long);
       left_player(so_long);
       eat_coin(so_long);
    }
    if (key == 126 ) 
    {
         check_exit_wall(so_long);
        up_player(so_long);
        eat_coin(so_long);
    }
    if (key == 125) 
    {
        check_exit_wall(so_long);
        down_player(so_long);
        eat_coin(so_long);
    }
    if (key == 53)
    {
        write(1, "You Exit The Game\n", 19);
        exit(0);
    }
    return key;
}
