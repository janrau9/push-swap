/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:11:18 by jberay            #+#    #+#             */
/*   Updated: 2023/12/22 09:27:55 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "stdlib.h"
#include <stdio.h>
# include <stdbool.h>
# include "unistd.h"
# include "limits.h"

typedef struct s_stack
{
	int				element;
	int				final_pos;
	int				chunk_pos;
	bool			above;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	ps_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ps_lstnew(int content);
int		ps_lstsize(t_stack *lst);
t_stack	*ps_lstlast(t_stack *lst);
void	ps_lstclear(t_stack **lst);
long	ps_atoi(t_stack *head, const char *str);

void	pa(t_stack **a_head, t_stack **b_head);
void	pb(t_stack **a_head, t_stack **b_head);
void	rra(t_stack **head);
void	rrb(t_stack **head);
void	rrr(t_stack **a_head, t_stack **b_head);
void	ra(t_stack **head);
void	rb(t_stack **head);
void	rr(t_stack **a_head, t_stack **b_head);
void	sa(t_stack **head);
void	sb(t_stack **head);
void	ss(t_stack **a_head, t_stack **b_head);

void	sort_final_pos(t_stack **head);
void	add_chunk_index(t_stack **head, int max);
void	split_to_chunks(t_stack **a_head, t_stack **b_head);
void	sort_three(t_stack **head);
void	sort_big_a(t_stack **a_head, t_stack **b_head, int max_num);
void	sort_big_b(t_stack **a_head, t_stack **b_head, int max_num);
void	split_stack(t_stack **a_head, t_stack **b_head);
void	add_stack_index(t_stack **head, int max_num);


int		ps_error(t_stack **head, char **argv, int flag);
void	free_split(char **argv);

int		check_b_revsorted(t_stack **head);

#endif