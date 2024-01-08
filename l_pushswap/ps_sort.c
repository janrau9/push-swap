/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:30:36 by jberay            #+#    #+#             */
/*   Updated: 2024/01/08 10:13:33 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_stack **head)
{
	t_stack	*hold;

	hold = find_max(*head);
	if (*head == hold)
		ra(head, false);
	else if ((*head)->next == hold)
		rra(head, false);
	if ((*head)->final_pos > (*head)->next->final_pos)
		sa(head, false);
}

void	sort_five(t_stack **a_head, t_stack **b_head)
{
	if (ps_lstsize(*a_head) > 3 && !sorted(*a_head))
		pb(a_head, b_head, false);
	if (ps_lstsize(*a_head) > 3 && !sorted(*a_head))
		pb(a_head, b_head, false);
	sort_three(a_head);
	while (*b_head)
	{
		init_b(*a_head, *b_head, 5);
		push_btoa(a_head, b_head);
	}
	min_top(a_head);
}

void	sort_big(t_stack **a_head, t_stack **b_head)
{
	int		i;
	int		j;
	int		size;

	i = 1;
	j = 0;
	size = ps_lstsize(*a_head);
	split_to_chunks(a_head, b_head, i, j);
	while (*a_head)
	{
		// split_to_chunks(a_head, b_head, i, j);
		i++;
		j = j + 2;
		split_to_chunks_one(a_head, b_head, i, j);
	}
	(find_max(*b_head))->cheapest = true;
	current_index(*b_head);
	prep_for_push(b_head, find_max(*b_head), 'b');
	pa(a_head, b_head, false);
	while (*b_head)
	{
		init_b(*a_head, *b_head, size);
		push_btoa(a_head, b_head);
	}
	min_top(a_head);
}
