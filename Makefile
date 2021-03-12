# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 11:33:38 by nepage-l          #+#    #+#              #
#    Updated: 2021/03/08 16:53:42 by nepage-l         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

HEADER		=			push_swa/

HEADER		=			checke/

LIB			=			libft.a

LIBS		=			libft/libft.a

SRC_PATH	=			push_swa

SRC_PATH2	=			checke

SRCS_NAME	=			push_swap.c \
						ft_operate.c

SRCS_NAME2	=			checker.c \
						get_next_line/get_next_line_utils.c \
						get_next_line/get_next_line.c

OBJS        =			${SRCS:.c=.o}

OBJS2        =			${SRCS2:.c=.o}

NAME		=			push_swap

NAME2		=			checker

RM			=			rm -f

FLAGS		=			-Wall -Wextra -Werror

SRCS		=			$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

SRCS2		=			$(addprefix $(SRC_PATH2)/,$(SRCS_NAME2))

# **************************************************************************** #
#                                REGLES                                        #
# **************************************************************************** #

all:                            $(NAME)

bonus: all

%.o: %.c                         $(HEADER) $(LIBS)
						@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
						@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

$(NAME):				$(LIB) $(OBJS) $(HEADER) $(OBJS2) $(HEADER2)
						@gcc $(OBJS) $(FLAGS) $(LIBS) -o $(NAME)
						@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling push_swap\033[0m"
						@gcc $(OBJS2) $(FLAGS) $(LIBS) -o $(NAME2)
						@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling checker\033[0m"

$(LIB):
								@$(MAKE) -C libft all								


clean:
								@$(MAKE) -C libft clean
								@echo "\x1b[36m[OK] \033[0m \x1b[34m Removing ALL File object\033[0m"
								@$(RM) $(OBJS) $(OBJS2)

fclean:                         clean
								@$(MAKE) -C libft fclean
								@echo "\x1b[36m[OK] \033[0m \x1b[32m All is Removing\033[0m"
								@$(RM) $(NAME) $(NAME2)

re:                                fclean all

ART:
		@echo "    ____             __                               "
		@echo "   / __ \__  _______/ /_     ______      ______ _____ "
		@echo "  / /_/ / / / / ___/ __ \   / ___/ | /| / / __ `/ __ \"
		@echo " / ____/ /_/ (__  ) / / /  (__  )| |/ |/ / /_/ / /_/ /"
		@echo "/_/    \__,_/____/_/ /_/  /____/ |__/|__/\__,_/ .___/ "
		@echo "                                             /_/      "
		@echo ""


.PHONY:                         clean fclean
