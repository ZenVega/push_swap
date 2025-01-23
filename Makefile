# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uschmidt <uschmidt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:42:30 by uschmidt          #+#    #+#              #
#    Updated: 2025/01/22 13:38:57 by uschmidt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = \
push_swap.c\
actions.c\
call_actions.c\
utils.c\
utils_2.c\
utils_3.c\
setup.c\
solve_turk.c\
find_cheapest.c\
solve_for_idx.c\

OFILES = $(CFILES:.c=.o)

DEPS = push_swap.h

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror
CFLAGS_SAN = -Wall -Wextra -Werror -fsanitize=leak

NAME = push_swap
 
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

ARGS = 5 8 2 9 -3

all: $(NAME) 

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) *.o $(LIBFT) -no-pie

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	$(MAKE) clean
	rm push_swap
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
