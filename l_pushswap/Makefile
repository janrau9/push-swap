# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 11:38:23 by jberay            #+#    #+#              #
#    Updated: 2024/01/04 13:00:28 by jberay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRCS 			=	main.c \
					ps_lstnew.c \
					ps_lstadd_back.c \
					ps_lstsize.c \
					ps_lstlast.c \
					ps_error.c \
					ps_atoi.c \
					ps_push_op.c \
					ps_rev_rotate_op.c \
					ps_rotate_op.c \
					ps_swap_op.c \
					ps_sort.c \
					ps_utils.c \
					init_a.c \
					init_b.c \
					initialize.c \
					split_to_chunks.c

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
					$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME) 

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft