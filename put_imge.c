/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:47:29 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/03 19:05:21 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	put_ground(t_long *so_long, t_win *s_win, int i, int j)
{
	int	x;
	int	y;

x = so_long->width * 50;
y = so_long->hight * 50;
s_win->img = mlx_xpm_file_to_image(s_win->mlx, "texture/ground.xpm", &x, &y);
	mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
	mlx_destroy_image(s_win->mlx, s_win->img);
}

void	put_collect(t_long *so_long, t_win *s_win, int i, int j)
{
	int	x;
	int	y;

	x = so_long->width * 50;
	y = so_long->hight * 50;
	s_win->img = mlx_xpm_file_to_image(s_win->mlx, "texture/coin7.xpm", &x, &y);
	mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
	mlx_destroy_image(s_win->mlx, s_win->img);
}

void	put_dor(t_long *so_long, t_win *s_win, int i, int j)
{
	int	x;
	int	y;

	x = so_long->width * 50;
	y = so_long->hight * 50;
	s_win->img = mlx_xpm_file_to_image(s_win->mlx, "texture/dor.xpm", &x, &y);
	mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
	mlx_destroy_image(s_win->mlx, s_win->img);
}

void	put_player(t_long *so_long, t_win *s_win)
{
	int	x;
	int	y;
	int	xp;
	int	yp;

	xp = so_long->xp * 50;
	yp = so_long->yp * 50;
	x = so_long->width * 50;
	y = so_long->hight * 50;
	s_win->img = mlx_xpm_file_to_image(s_win->mlx, "texture/ply.xpm", &x, &y);
	mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, xp, yp);
	mlx_destroy_image(s_win->mlx, s_win->img);
}

void	put_wall(t_long *so_long, t_win *s_win, int i, int j)
{
	int	x;
	int	y;

	x = so_long->width * 50;
	y = so_long->hight * 50;
	s_win->img = mlx_xpm_file_to_image(s_win->mlx, "texture/wall.xpm", &x, &y);
	mlx_put_image_to_window(s_win->mlx, s_win->win, s_win->img, j, i);
	mlx_destroy_image(s_win->mlx, s_win->img);
}
