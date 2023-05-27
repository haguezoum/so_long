
NAME = gnl.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =  get_next_line.c
OBJ = $(SRC:.c=.o)

HEADER = get_next_line.h

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) -c $< $(CFLAGS)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ) 

clean : 
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re: fclean all