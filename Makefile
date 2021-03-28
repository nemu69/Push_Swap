# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nepage-l <nepage-l@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 11:33:38 by nepage-l          #+#    #+#              #
#    Updated: 2021/03/15 17:09:16 by nepage-l         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

HEADER		=			push_swa/

HEADER		=			checke/

LIBS		=			libft/libft.a

SRC_PATH	=			push_swa

SRC_PATH2	=			checke

SRCS_NAME	=			push_swap.c \
						ft_operate.c \
						ft_fct.c \
						ft_papb.c \
						ft_rarbrr.c \
						ft_rrarrbrrr.c \
						ft_sasbss.c \
						../get_next_line/get_next_line_utils.c \
						../get_next_line/get_next_line.c

SRCS_NAME2	=			checker.c \
						ft_read.c \
						ft_papb.c \
						ft_rarbrr.c \
						ft_rrarrbrrr.c \
						ft_sasbss.c \
						../get_next_line/get_next_line_utils.c \
						../get_next_line/get_next_line.c

OBJS        =			${SRCS:.c=.o}

OBJS2        =			${SRCS2:.c=.o}

NAME		=			push_swap

NAME2		=			checker

RM			=			rm -f

FLAGS		=			-Wall -Wextra -Werror -O3

SRCS		=			$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

SRCS2		=			$(addprefix $(SRC_PATH2)/,$(SRCS_NAME2))

# **************************************************************************** #
#                                REGLES                                        #
# **************************************************************************** #

all: $(NAME) $(NAME2) 

%.o: %.c $(HEADER)
						@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
						@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

$(NAME): $(LIBS) $(OBJS) $(HEADER) | ART
						@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling push_swap\n\033[0m"
						gcc $(OBJS) $(FLAGS) $(LIBS) -o $(NAME)
						

$(NAME2): $(LIBS) $(OBJS2) $(HEADER2) | ART2
						@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling checker\n\033[0m"
						gcc $(OBJS2) $(FLAGS) $(LIBS) -o $(NAME2)

$(LIBS): FORCE
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

ART: FORCE
		@echo "    ____             __                               "
		@echo "   / __ \__  _______/ /_     ______      ______ _____ "
		@echo "  / /_/ / / / / ___/ __ \   / ___/ | /| / / __ '/ __ \""
		@echo " / ____/ /_/ (__  ) / / /  (__  )| |/ |/ / /_/ / /_/ /"
		@echo "/_/    \__,_/____/_/ /_/  /____/ |__/|__/\__,_/ .___/ "
		@echo "                                             /_/      "
		@echo ""
		
ART2: FORCE
		@echo " .d8888b.    888    888   8888888888    .d8888b.    888    d8P    8888888888   8888888b.  "
		@echo "d88P  Y88b   888    888   888          d88P  Y88b   888   d8P     888          888   Y88b "
		@echo "888    888   888    888   888          888    888   888  d8P      888          888    888 "
		@echo "888          8888888888   8888888      888          888d88K       8888888      888   d88P "
		@echo "888          888    888   888          888          8888888b      888          8888888P"  ""
		@echo "888    888   888    888   888          888    888   888  Y88b     888          888 T88b   "
		@echo "Y88b  d88P   888    888   888          Y88b  d88P   888   Y88b    888          888  T88b  "
		@echo "  "Y8888P"     888    888   8888888888     "Y8888P"     888    Y88b   8888888888   888   T88b "

.PHONY: ART ART2 clean fclean

FORCE: ;
