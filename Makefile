# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uschmidt <uschmidt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:42:30 by uschmidt          #+#    #+#              #
#    Updated: 2025/01/20 15:10:22 by uschmidt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = \
push_swap.c\
actions.c\
call_actions.c\
utils.c\
utils_2.c\
setup.c\
simple_solve.c\
solve_2.c\
find_cheapest.c\
solve_for_idx.c\

OFILES = $(CFILES:.c=.o)

DEPS = push_swap.h

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror
CFLAGS_SAN = -Wall -Wextra -Werror -fsanitize=leak

NAME = push_swap
 
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

ARGS = 5 8 2 9 -3

all: $(NAME) 

$(NAME): $(OFILES) $(PRINTF)
	@ar x $(PRINTF)  # Extract object files from libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME) *.o

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

debug: $(OFILES) $(PRINTF)
	@ar x $(PRINTF)  # Extract object files from printf.a
	$(CC) $(CFLAGS) -o $(NAME)_deb *.o
	gdb --args ./$(NAME)_deb $(ARGS)

clean:
	rm -f *.o
	$(MAKE) -C $(PRINTF_DIR) clean

fclean:	clean
	rm -f *.o
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re debug
