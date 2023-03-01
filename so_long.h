/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 03:10:10 by himejjad          #+#    #+#             */
/*   Updated: 2023/03/01 23:24:04 by himejjad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include "get_next_line.h"
typedef struct s_win
{
    void *mlx;
    void *win;
    void *img;
    int x,y,g,f,j,i;
}   t_win;

typedef struct s_slong
{
    int player;
    int xp;
    int yp;
    int collect;
    int exit;
    int width;
    int hight;
    char *stock;
    char **maps;
    char **map_copy;
    char **map_m;
    int fd;
    t_win *s_win;
}   t_long;

int	ft_strcmp(char *s1,char *s2);
char	**ft_split(char  *s, char c);
char	*ft_line(char *buffer);
void error();
int count_lines(char **map);
int check_ber(char *file);
void map_check(t_long *so_long);
void chec_pos(t_long *so_long);
void put_ground(t_long *so_long, t_win *s_win, int i, int j);
void put_player(t_long *so_long, t_win *s_win);
void put_img(t_long *so_long);
void put_dor(t_long *so_long, t_win *s_win, int i, int j);
void put_wall(t_long *so_long, t_win *s_win, int i, int j);
void put_collect(t_long *so_long, t_win *s_win, int i, int j);
void check_exit_coin(t_long *so_long);
void parce_map(t_long  *so_long);
void get_stock(t_long  *so_long);
void    ft_int(t_long *so_long);
void check_d_newline(char *map);
void check_wall(t_long *so_long);
void check_char(t_long *so_long);
int key_handler(int key, t_long *so_long);
t_win *ft_initial(t_long *so_long);
void right_player(t_long *so_long);
void draw_map(t_long *so_long);
t_long *find_player(t_long *so_long);
void left_player(t_long *so_long);
void up_player(t_long *so_long);
void down_player(t_long *so_long);
int key_handler(int key, t_long *so_long);
void stop_player(t_long *so_long);
void eat_coin( t_long *so_long);

#endif
