/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:11:18 by jberay            #+#    #+#             */
/*   Updated: 2024/01/05 13:15:43 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "stdlib.h"
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

void	pa(t_stack **a_head, t_stack **b_head, bool print);
void	pb(t_stack **a_head, t_stack **b_head, bool print);
void	rra(t_stack **head, bool print);
void	rrb(t_stack **head, bool print);
void	rrr(t_stack **a_head, t_stack **b_head, bool print);
void	ra(t_stack **head, bool print);
void	rb(t_stack **head, bool print);
void	rr(t_stack **a_head, t_stack **b_head, bool print);
void	sa(t_stack **head, bool print);
void	sb(t_stack **head, bool print);
void	ss(t_stack **a_head, t_stack **b_head, bool print);

void	sort_three(t_stack **head);
void	sort_five(t_stack **head, t_stack **b_head);
void	sort_big(t_stack **a_head, t_stack **b_head);

void	initialize(t_stack **a_head, char **argv, int i);
void	init_b(t_stack *a_head, t_stack *b_head, int size);
void	current_index(t_stack *head);
void	cost(t_stack *a_head, t_stack *b_head);
void	cheapest(t_stack *head, int size, int j);
void	push_btoa(t_stack **a_head, t_stack **b_head);
void	min_top(t_stack **a_head);
void	prep_for_push(t_stack **head, t_stack *top, char name);

int		sorted(t_stack *head);
void	sort_final_pos(t_stack **head);
t_stack	*find_max(t_stack *head);
t_stack	*find_min(t_stack *head);
t_stack	*get_cheapest(t_stack *head);

void	split_to_chunks(t_stack **a_head, t_stack **b_head, int i, int j);
void	split_to_chunks_one(t_stack **a_head, t_stack **b_head, int i, int j);
int		chunk_size(int size);

int		ps_error(t_stack **head, char **argv, int flag);
void	free_split(char **argv);

#endif