/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 02:51:09 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/03 19:10:24 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	flood_fill(char **map, int xp, int yp)
{
	if (map[yp][xp] == '1' || map[yp][xp] == '*')
		return ;
	map[yp][xp] = '*';
	flood_fill(map, xp + 1, yp);
	flood_fill(map, xp, yp + 1);
	flood_fill(map, xp - 1, yp);
	flood_fill(map, xp, yp - 1);
}

int	main(int ac, char **av)
{
	t_long	*so_long;

	so_long = malloc(sizeof(t_long));
	so_long->fd = open (av[1], O_RDONLY);
	if (ac == 2 && check_ber(av[1]))
	{
		parce_map(so_long);
	}
	else
		error();
	put_img(so_long);
}
