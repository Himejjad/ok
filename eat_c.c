/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:34:04 by himejjad            #+#    #+#             */
/*   Updated: 2023/02/28 20:54:19 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void    ft_int(t_long *so_long)
{
    so_long->player = 0;
    so_long->collect = 0;
    so_long->exit = 0;
    so_long->hight = count_lines(so_long->maps);
    so_long->width = ft_strlen(so_long->maps[0]); 
}

void eat_coin( t_long *so_long)
{
    if (so_long->collect >= 0)
    {
        if (so_long->maps[so_long->yp][so_long->xp] == 'C')
        {
            so_long->maps[so_long->yp][so_long->xp] = '0';
            so_long->collect--;
            draw_map(so_long);
        }
        else if (so_long->maps[so_long->yp][so_long->xp] == 'C')
        {
            so_long->maps[so_long->yp][so_long->xp] = '0';
            so_long->collect--;
            draw_map(so_long);
        }
        else if (so_long->maps[so_long->yp][so_long->xp] == 'C')
        {
            so_long->maps[so_long->yp][so_long->xp] = '0';
            so_long->collect--;
            draw_map(so_long);
        }
        else if (so_long->maps[so_long->yp][so_long->xp] == 'C')
        {
            so_long->maps[so_long->yp][so_long->xp] = '0';
            so_long->collect--;
            draw_map(so_long);
        }
    }
}
