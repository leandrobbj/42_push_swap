# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 16:04:42 by lbraga            #+#    #+#              #
#    Updated: 2025/10/29 22:54:36 by lbraga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
HEADER	=	push_swap.h
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I.
RM		=	rm -f

SRC		=	src/ps_main.c src/ps_exit.c src/ps_index.c src/ps_sort.c src/ps_moves.c

OBJ		=	$(SRC:.c=.o)
LIBFT_D	=	src/libft
LIBFT	=	$(LIBFT_D)/libft.a

all: $(NAME)
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "$(NAME) compiled"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_D) --no-print-directory

%.o: %.c $(HEADER)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIBFT_D) --no-print-directory
	@echo "Objects deleted"

fclean: clean	
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFT_D) --no-print-directory
	@echo "Library deleted"

re: fclean all

.PHONY: all clean fclean re