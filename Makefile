# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haguezou <haguezou@student.1337.ma >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 22:39:11 by haguezou          #+#    #+#              #
#    Updated: 2023/05/26 22:12:03 by haguezou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 

SRC = main.c check_map.c check_path.c error.c init_game.c image.c move.c move_counter.c exit_game.c

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
#

HEADER = so_long.h 

OBJ = ${SRC:.c=.o}

LIBFT = ./libft
GNL = ./get_next_line
LIBRARIES = ./libft/libft.a ./get_next_line/gnl.a
MAP = map.ber

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	make -C $(LIBFT)
	make -C $(GNL)
	$(CC) $(SRC) $(CFLAGS) $(LIBRARIES) -I /usr/local/include -L /usr/local/bin -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean :
	make clean -C $(LIBFT) 
	make clean -C $(GNL)
	rm -rf $(OBJ)

fclean : clean
	make fclean -C $(LIBFT)
	make fclean -C $(GNL)
	rm -rf $(NAME)

re : fclean all