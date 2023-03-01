/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:26:45 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/01 21:43:14 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void chec_pos(t_long *so_long)
{
    int i = 0;
    int j;
    while(so_long->maps[i])
    {
        j = 0;
        while (so_long->maps[i][j])
        {
            if (so_long->maps[i][j] == 'P')
            {
                so_long->yp = i;
                so_long->xp = j;
                return;
            }
            j++;
        }
        i++;
    }
}
t_win *ft_initial(t_long *so_long)
{
    t_win *s_win = malloc(sizeof(t_win));
    s_win->mlx = mlx_init();
    s_win->y = so_long->hight*50;
    s_win->x = so_long->width*50;
    s_win->f = 0;
    s_win->i = 0;
    return(s_win);
}
void put_img(t_long *so_long)
{
    so_long->s_win = ft_initial(so_long);
    so_long->s_win->win = mlx_new_window(so_long->s_win->mlx, so_long->s_win->x, so_long->s_win->y, "soo_long");
    while(so_long->maps[so_long->s_win->f])
    {
        so_long->s_win->j = 0;
        so_long->s_win->g = 0;
        while (so_long->maps[so_long->s_win->f][so_long->s_win->g])
        {
            if (so_long->maps[so_long->s_win->f][so_long->s_win->g] == 'C')
                put_collect(so_long, so_long->s_win, so_long->s_win->i, so_long->s_win->j);
            else if (so_long->maps[so_long->s_win->f][so_long->s_win->g] == 'P' )
            {
                so_long->xp = so_long->s_win->g;
                so_long->yp = so_long->s_win->f;
                put_player(so_long, so_long->s_win);
            }
            else if (so_long->maps[so_long->s_win->f][so_long->s_win->g] == '1')
                put_wall(so_long, so_long->s_win, so_long->s_win->i, so_long->s_win->j);
            else if (so_long->maps[so_long->s_win->f][so_long->s_win->g] == 'E')
                put_dor(so_long, so_long->s_win, so_long->s_win->i, so_long->s_win->j);
            else if (so_long->maps[so_long->s_win->f][so_long->s_win->g] == '0')
                put_ground(so_long, so_long->s_win, so_long->s_win->i, so_long->s_win->j);
            so_long->s_win->g++;
            so_long->s_win->j += 50;
        }
        so_long->s_win->i += 50;
        so_long->s_win->f++; 
    }
    mlx_key_hook(so_long->s_win->win, key_handler, so_long);
    mlx_loop(so_long->s_win->mlx);
} 

void get_stock(t_long  *so_long)
{
    char * dst = get_next_line(so_long->fd);
    if (!dst || so_long->fd < 0)
        error();
    so_long->stock = malloc(1);
    so_long->stock[0] = '\0';
    while(dst)
    {
        so_long->stock = ft_strjoin(so_long->stock, dst);
        free(dst);
        dst = get_next_line(so_long->fd);
    }
    free(dst);
}

void parce_map(t_long  *so_long)
{
        get_stock(so_long);
        so_long->maps = ft_split(so_long->stock, '\n');
        so_long->map_copy = ft_split(so_long->stock, '\n');
        so_long->map_m = ft_split(so_long->stock, '\n');
        ft_int(so_long);
        check_d_newline(so_long->stock);
        check_wall(so_long);
        // write(1,"\033[32m", 5);
        // write(1,"VALID\n", 7);
}