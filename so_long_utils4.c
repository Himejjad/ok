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
    
    (void )so_long;
    // i = 0;
    // j = 0;
    printf("%d\n", key);
    // if (key == 125) // down
    // {
    //     i += 50;
    //     img = mlx_xpm_file_to_image(s_win->mlx, "dor.xpm", &x, &y);
    //     mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
    //     mlx_destroy_image(s_win->mlx, s_win->img)
    // }
    // if (key == 126) // up
    // {
    //     img = mlx_xpm_file_to_image(s_win->mlx, "ground.xpm", &x, &y);
    //     mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
    //     mlx_destroy_image(s_win->mlx, s_win->img)
    //     i -= 50;
    //     img = mlx_xpm_file_to_image(s_win->mlx, "dor.xpm", &x, &y);
    //     mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
    //     mlx_destroy_image(s_win->mlx, s_win->img)
    // }
    // if (key == 123) // right
    // {
    //     j += 50;
    //     img = mlx_xpm_file_to_image(s_win->mlx, "dor.xpm", &x, &y);
    //     mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
    //     mlx_destroy_image(s_win->mlx, s_win->img)
    // }
    // if (key == 124) // left
    // {
    //     j -= 50;
    //     img = mlx_xpm_file_to_image(s_win->mlx, "dor.xpm", &x, &y);
    //     mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
    //     mlx_destroy_image(s_win->mlx, s_win->img)
    // }
    return key;
}




// void ft_move(t_long *so_long)
// {
    
    
// }