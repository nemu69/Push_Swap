# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 16:41:01 by nepage-l          #+#    #+#              #
#    Updated: 2021/03/15 11:20:20 by nepage-l         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = 		libft.a

SRCS = 		ft_isdigit.c \
			ft_memcmp.c \
			ft_putstr.c \
			ft_tolower.c \
			ft_atoi.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_split.c \
			ft_strmapi.c \
			ft_toupper.c \
			ft_bzero.c \
			ft_memmove.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_calloc.c \
			ft_memset.c \
			ft_strdup.c \
			ft_strnstr.c \
			ft_isalnum.c \
			ft_putchar_fd.c \
			ft_strrchr.c \
			ft_isalpha.c \
			ft_memccpy.c \
			ft_putendl_fd.c \
			ft_strlcat.c \
			ft_strtrim.c \
			ft_isascii.c \
			ft_memchr.c \
			ft_putnbr_fd.c \
			ft_strlcpy.c \
			ft_lstnew_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c

HEADER = 	libft.h

OBJS = ${SRCS:.c=.o}


%.o: %.c $(HEADER)
	gcc -Wall -Wextra -Werror -I $(HEADER) -c $< -o $@

$(NAME) : $(HEADER) $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f  $(NAME)

re: fclean all

.PHONY: clean re fclean all
