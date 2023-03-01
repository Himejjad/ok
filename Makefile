# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: himejjad <himejjad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 23:14:14 by himejjad          #+#    #+#              #
#    Updated: 2023/03/01 16:54:00 by himejjad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long_utils.c get_next_line_utils.c so_long_utils3.c get_next_line.c so_long_utils2.c put_imge.c so_long_utils4.c
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
MLX = -lmlx -framework OpenGL -framework AppKit
SRC_SOLONG = so_long.c ${SRC}

all :  so_long

so_long : ${SRC_SOLONG} 
	@gcc  ${MLX} ${SRC_SOLONG} -o so_long
	@echo "all's ready"
clean :
	@rm -rf server so_long
	@echo "all's clean"
fclean :clean

re :fclean all