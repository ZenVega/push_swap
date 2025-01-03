# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uschmidt <uschmidt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:42:30 by uschmidt          #+#    #+#              #
#    Updated: 2025/01/03 18:00:37 by uschmidt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = \
push_swap.c\
actions.c

OFILES = $(CFILES:.c=.o)

DEPS = push_swap.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=leak

NAME = push_swap
 
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME) 

$(NAME): $(OFILES) $(PRINTF)
	@ar x $(PRINTF)  # Extract object files from printf.a
	$(CC) $(CFLAGS) -o $(NAME) *.o

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	$(MAKE) -C $(PRINTF_DIR) clean

fclean:	clean
	rm -f *.o
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
