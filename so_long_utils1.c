/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:50:49 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/03 19:09:25 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	write(1, "\033[31m", 5);
	write(1, "ERROR\n", 7);
	exit(1);
}

void	ft_int(t_long *so_long)
{
	so_long->player = 0;
	so_long->collect = 0;
	so_long->exit = 0;
	so_long->hight = count_lines(so_long->maps);
	so_long->width = ft_strlen(so_long->maps[0]);
	so_long->move = 0;
}

void	moves(t_long *so_long)
{
	check_exit(so_long);
	so_long->move++;
	ft_printf("moves : %d\n", so_long->move);
}

t_win	*ft_initial(t_long *so_long)
{
	t_win	*s_win;

	s_win = malloc(sizeof(t_win));
	s_win->mlx = mlx_init();
	s_win->y = so_long->hight * 50;
	s_win->x = so_long->width * 50;
	s_win->f = 0;
	s_win->i = 0;
	return (s_win);
}

int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
