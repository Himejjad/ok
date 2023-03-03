# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 23:14:14 by himejjad          #+#    #+#              #
#    Updated: 2023/03/03 18:17:09 by himejjad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1 = so_long_utils.c get_next_line_utils.c get_next_line.c check_map.c put_imge.c  move_player.c draw_map.c check_exit_coin.c map.c so_long_utils1.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_hexdec.c ft_unsputnbr.c
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MLX = -lmlx -framework OpenGL -framework AppKit
SRC_SOLONG = so_long.c ${SRC1} 

all :  so_long

so_long : ${SRC_SOLONG} 
	@cc ${FLAGS} ${MLX} ${SRC_SOLONG} -o so_long
	@echo "all's ready"
clean :
	@rm -rf server so_long
	@echo "all's clean"
fclean :clean

re :fclean all