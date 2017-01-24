# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akesraou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 17:12:41 by akesraou          #+#    #+#              #
#    Updated: 2017/01/09 16:40:01 by akesraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
RM = rm -f
OBJS = $(SRCS:.c=.o)
SRCS =	ft_memccpy.c \
		ft_putnbr.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_memchr.c \
		ft_putnbr_fd.c \
		ft_striter.c \
		ft_strnew.c \
		ft_atoi.c \
		ft_memcmp.c \
		ft_putstr.c \
		ft_striteri.c \
		ft_strnstr.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_putstr_fd.c \
		ft_strjoin.c \
		ft_strrchr.c \
		ft_isalnum.c \
		ft_memdel.c \
		ft_strcat.c \
		ft_strlcat.c \
		ft_strsplit.c \
		ft_isalpha.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_strstr.c \
		ft_isascii.c \
		ft_memset.c \
		ft_strclr.c \
		ft_strmap.c \
		ft_strsub.c \
		ft_isdigit.c \
		ft_putchar.c \
		ft_strcmp.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_isprint.c \
		ft_putchar_fd.c \
		ft_strcpy.c \
		ft_strncat.c \
		ft_tolower.c \
		ft_itoa.c \
		ft_putendl.c \
		ft_strdel.c \
		ft_strncmp.c \
		ft_toupper.c \
		ft_memalloc.c \
		ft_putendl_fd.c \
		ft_strdup.c \
		ft_strncpy.c \
		ft_lstadd.c \
		ft_lstnew.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \

all : $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
