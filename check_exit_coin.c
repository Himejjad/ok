/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_coin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:49:20 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/03 18:27:27 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	eat_coin( t_long *so_long)
{
	if (so_long->collect >= 0)
	{
		if (so_long->maps[so_long->yp][so_long->xp] == 'C')
		{
			so_long->maps[so_long->yp][so_long->xp] = '0';
			so_long->collect--;
			draw_map(so_long);
		}
	}
}

void	check_exit(t_long *so_long)
{
	if (so_long->collect == 0
		&& so_long->maps[so_long->yp +1][so_long->xp] == 'E')
		so_long->maps[so_long->yp + 1][so_long->xp] = 'x';
	else if (so_long->collect == 0
		&& so_long->maps[so_long->yp - 1][so_long->xp] == 'E')
		so_long->maps[so_long->yp - 1][so_long->xp] = 'x';
	else if (so_long->collect == 0
		&& so_long->maps[so_long->yp][so_long->xp - 1] == 'E')
		so_long->maps[so_long->yp][so_long->xp - 1] = 'x';
	else if (so_long->collect == 0
		&& so_long->maps[so_long->yp][so_long->xp + 1] == 'E')
		so_long->maps[so_long->yp][so_long->xp + 1] = 'x';
	if (so_long->maps[so_long->yp][so_long->xp] == 'x')
	{
		so_long->move++;
		ft_printf("moves : %d\n", so_long->move);
		ft_printf("All collect was done\n");
		exit(0);
	}
}
