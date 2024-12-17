# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uschmidt <uschmidt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:42:30 by uschmidt          #+#    #+#              #
#    Updated: 2024/12/17 16:49:57 by uschmidt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = \
push_swap.c

OFILES = $(CFILES:.c=.o)

DEPS = push_swap.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=leak

NAME = push_swap
 
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) 

$(NAME): $(OFILES) $(LIBFT) 
	@ar x $(LIBFT)  # Extract object files from libft.a
	$(CC) $(CFLAGS) -o $(NAME) *.o

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
