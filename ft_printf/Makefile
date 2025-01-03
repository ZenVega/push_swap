# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uschmidt <uschmidt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:42:30 by uschmidt          #+#    #+#              #
#    Updated: 2024/12/02 10:48:08 by uschmidt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFILES = \
ft_putnbr_base.c\
ft_printnbr.c\
ft_print_utils.c\
ft_printprcnt.c\
ft_printf.c

OFILES = $(CFILES:.c=.o)

DEPS = ft_printf.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=leak

NAME = libftprintf.a
 
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) 

$(NAME): $(OFILES) $(LIBFT) 
	@echo "Creating $(NAME)..."
	ar rcs $(NAME) $(OFILES)
	@echo "Merging libft.a into $(NAME)..."
	@ar x $(LIBFT) # Extract object files from libft.a
	@ar rcs $(NAME) *.o  # Add all object files into libftprintf.a

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

test: $(NAME) main.c
	$(CC) main.c -L$(DEPS) -lftprintf -L$(LIBFT_DIR) -lft -o test_program

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
