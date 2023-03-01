/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:59:24 by himejjad            #+#    #+#             */
/*   Updated: 2023/02/28 20:54:48 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void put_ground(t_long *so_long, t_win *s_win, int i, int j)
{
    int x = so_long->width*50;
    int y = so_long->hight*50;
    s_win->img = mlx_xpm_file_to_image(s_win->mlx, "ground.xpm", &x, &y);
    mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
    mlx_destroy_image(s_win->mlx, s_win->img);
}
void put_collect(t_long *so_long, t_win *s_win, int i, int j)
{
    int x = so_long->width*50;
    int y = so_long->hight*50;
    put_ground(so_long, s_win, s_win->i, s_win->j);
    s_win->img = mlx_xpm_file_to_image(s_win->mlx, "coin7.xpm", &x, &y);
    mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
    mlx_destroy_image(s_win->mlx, s_win->img);
}
void put_dor(t_long *so_long, t_win *s_win, int i, int j)
{
    int x = so_long->width*50;
    int y = so_long->hight*50;
    put_ground(so_long, s_win, s_win->i, s_win->j);
    s_win->img = mlx_xpm_file_to_image(s_win->mlx, "dor.xpm", &x, &y);
    mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
    mlx_destroy_image(s_win->mlx, s_win->img);
}
void put_player(t_long *so_long, t_win *s_win, int i, int j)
{
    int x = so_long->width*50;
    int y = so_long->hight*50;
    put_ground(so_long, s_win, s_win->i, s_win->j);
    s_win->img = mlx_xpm_file_to_image(s_win->mlx, "player7.xpm", &x, &y);
    mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
    mlx_destroy_image(s_win->mlx, s_win->img);
}
void put_wall(t_long *so_long, t_win *s_win, int i, int j)
{
    int x = so_long->width*50;
    int y = so_long->hight*50;
    put_ground(so_long, s_win, s_win->i, s_win->j);
    s_win->img = mlx_xpm_file_to_image(s_win->mlx, "wall.xpm", &x, &y);
    mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
    mlx_destroy_image(s_win->mlx, s_win->img);
}