/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:27:13 by himejjad          #+#    #+#             */
/*   Updated: 2023/02/28 20:54:42 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void error()
{
    write(1, "\033[31m", 5);
    write(1, "ERROR\n", 7);
    exit(1);
}

int count_lines(char **map)
{
    int i;

    i = 0;
    while (map[i]) 
        i++;
    return (i);
}

void map_check(t_long *so_long)
{
    int first_line  = so_long->width;
    int i;

    i = 1;
    while (i < so_long->hight)
    {
        if (ft_strlen (so_long->maps[i]) != first_line)
            error();
        i++;
    }
    
}

int check_ber(char *file)
{
    int len = ft_strlen(file);
    int i = 0;
    if (!file)
        error();
    while (file[i] && ft_strcmp(file + (len - 4), ".ber") == 0)
        i++;
    if (len > 4 && ft_strcmp(file + (len - (i - 4)), ".ber") == 0)
        return (1);
     else 
        return (0);
}


