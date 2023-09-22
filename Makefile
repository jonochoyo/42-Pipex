# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 14:42:23 by jchoy-me          #+#    #+#              #
#    Updated: 2023/09/22 17:26:59 by jchoy-me         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c

all: $(NAME)

$(NAME): 
			@make all -C libft
			$(CC) $(CFLAGS) $(SRCS) -L./libft -lft -o $(NAME)

clean:
		@rm -f $(NAME)
		@make fclean -C libft
		@echo "Cleaning files..."

fclean: clean

re: fclean all

.PHONY: all clean fclean re