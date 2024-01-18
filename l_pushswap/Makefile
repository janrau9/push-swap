# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 11:38:23 by jberay            #+#    #+#              #
#    Updated: 2024/01/15 13:22:28 by jberay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
NAME_LIB		=	push_swap_lib.a


CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRCS 			=	ps_main.c \
					ps_lstnew.c \
					ps_lstadd_back.c \
					ps_lstsize.c \
					ps_lstlast.c \
					ps_error.c \
					ps_initialize.c \
					ps_push_op.c \
					ps_rev_rotate_op.c \
					ps_rotate_op.c \
					ps_swap_op.c \
					ps_sort.c \
					ps_utils.c \
					init_b.c \
					split_to_chunks.c \
					ps_push_swap.c \
					ps_lis.c

BONUS_SRC		=	checker_bonus.c 
	
OBJS			=	$(SRCS:%.c=%.o)

BONUS_OBJS		= 	$(BONUS_SRC:.c=.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS) $(NAME_LIB)
					$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME) 

$(NAME_LIB):		$(OBJS)
					ar -rcs $(NAME_LIB) $^
					ar -d $(NAME_LIB) ps_main.o
					
%.o:%.c
					$(CC) $(CFLAGS) -c $< -o $@		
							
$(LIBFT):
					make -C $(LIBFT_PATH) all

bonus:				.bonus

.bonus:				$(BONUS_OBJS) $(NAME_LIB) $(LIBFT)
					$(CC) $(FLAGS) $(LIBFT) $(NAME_LIB) $(BONUS_OBJS) -o checker
					touch .bonus
					

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) .bonus
					$(RM) $(OBJS)
					$(RM) $(BONUS_OBJS)
					$(RM) $(NAME_LIB)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)
					$(RM) checker
					

re:					fclean all

.PHONY:				all bonus clean fclean re libft