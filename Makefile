# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akesraou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 10:26:58 by akesraou          #+#    #+#              #
#    Updated: 2017/01/04 12:39:21 by akesraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft/libft.a
FLAGS = -Wall -Werror -Wextra
RM = rm -f
OBJS = $(SRCS:.c=.o)
SRCS = main.c
EXEC = fdf
MF = make fclean

.PHONY: all clean fclean re

all: $(EXEC)

$(EXEC):
	$(MF) -C libft/
	make -C libft/
	gcc $(FLAGS) -o $(EXEC) $(NAME) $(SRCS) -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(EXEC)

re: fclean all
