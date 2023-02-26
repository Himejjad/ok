/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:34:04 by aaizza            #+#    #+#             */
/*   Updated: 2023/02/26 23:35:01 by aaizza           ###   ########.fr       */
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