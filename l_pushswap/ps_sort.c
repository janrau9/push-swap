/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:14:58 by jberay            #+#    #+#             */
/*   Updated: 2024/01/18 11:19:06 by jberay           ###   ########.fr       */
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
		init_b(*a_head, *b_head);
		push_btoa(a_head, b_head);
	}
	current_index(*a_head);
	min_top(a_head);
}

void	sort_big(t_stack **a_head, t_stack **b_head)
{
	int		size;
	t_stack	*ptr;

	ptr = *b_head;
	size = ps_lstsize(*a_head);
	lis(a_head);
	split_to_chunks(a_head, b_head, size);
	if (ps_lstsize(*a_head) == 3)
		sort_three(a_head);
	while (*b_head)
	{
		init_b(*a_head, *b_head);
		push_btoa(a_head, b_head);
	}
	current_index(*a_head);
	min_top(a_head);
}
