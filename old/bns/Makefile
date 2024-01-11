# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 15:06:11 by jberay            #+#    #+#              #
#    Updated: 2024/01/05 15:21:26 by jberay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	checker

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
PS_LIB			=	../push_swap_lib.a

SRCS 			=	checker_bonus.c \
					get_next_line.c

OBJS			=	$(SRCS:%.c=%.o)

LIBFT_PATH		=	../libft
LIBFT			=	$(LIBFT_PATH)/libft.a

%.o:%.c
					$(CC) $(CFLAGS) -c $< -o $@	


all:				$(NAME)

$(NAME):			$(OBJS) $(PS_LIB)
					$(CC) $(CFLAGS) $(LIBFT) $(OBJS) $(PS_LIB) -o $(NAME)
					cp $(NAME) ../	

$(PS_LIB):			
					cd ../ && make

$(LIBFT):
					make -C $(LIBFT_PATH) all

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)
					cd ../ && $(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft