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

int key_handler(int key, t_long *so_long)
{
    // int j;
    // int i;
    // int x = so_long->width*50;
    // int y = so_long->hight*50;
    // t_win *s_win = ft_initial(so_long);
    
    // i = 0;
    // j = 0;
    printf("%d\n", so_long->yp);
    if (key == 124) 
    {
       up_player(so_long);
    }
    if (key == 53)
    {
        write(1, "You Exit The Game\n", 19);
        exit(0);
    }
    return key;
}
