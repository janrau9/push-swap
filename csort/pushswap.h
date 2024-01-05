/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:11:18 by jberay            #+#    #+#             */
/*   Updated: 2024/01/04 14:26:07 by jberay           ###   ########.fr       */
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
	bool			above;
	bool			cheapest;
	int				index;
	int				push_cost;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
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

void	initialize(t_stack **a_head, char **argv, int i, int is_split);
int		sorted(t_stack *head);
void	sort_final_pos(t_stack **head);
void	sort_three(t_stack **head);
void	sort_five(t_stack **head, t_stack **b_head);
void	sort_big(t_stack **a_head, t_stack **b_head);

t_stack	*find_max(t_stack *head);
t_stack	*find_min(t_stack *head);
void	init_a(t_stack *a_head, t_stack *b_head);
void	split_to_chunks(t_stack **a_head, t_stack **b_head, int i, int j);
void	init_b(t_stack *a_head, t_stack *b_head);
t_stack	*get_cheapest(t_stack *head);
void	current_index(t_stack *head);
void	cheapest(t_stack *head);
void	cost(t_stack *a_head, t_stack *b_head);
int		ps_error(t_stack **head, char **argv, int flag);
void	free_split(char **argv);


#endif