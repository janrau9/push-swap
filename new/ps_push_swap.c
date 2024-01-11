/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:39:18 by jberay            #+#    #+#             */
/*   Updated: 2024/01/08 15:51:46 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate(t_stack **a_head, t_stack **b_head, t_stack *cheapest)
{
	while (*b_head != cheapest && *a_head != cheapest->target)
	{
		rr(a_head, b_head, false);
	}
	current_index(*a_head);
	current_index(*b_head);
}

static void	rev_rotate(t_stack **a_head, t_stack **b_head, t_stack *cheapest)
{
	while (*b_head != cheapest && *a_head != cheapest->target)
	{
		rrr(a_head, b_head, false);
	}
	current_index(*a_head);
	current_index(*b_head);
}

void	push_btoa(t_stack **a_head, t_stack **b_head)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*b_head);
	if (cheapest->above && cheapest->target->above)
		rotate(a_head, b_head, cheapest);
	else if (!(cheapest->above) && !(cheapest->target->above))
		rev_rotate(a_head, b_head, cheapest);
	prep_for_push(a_head, cheapest->target, 'a');
	prep_for_push(b_head, cheapest, 'b');
	pa(a_head, b_head, false);
}

void	min_top(t_stack **a_head)
{
	while ((*a_head)->final_pos != find_min(*a_head)->final_pos)
	{
		if (find_min(*a_head)->above)
			ra(a_head, false);
		else
			rra(a_head, false);
	}
}

void	prep_for_push(t_stack **head, t_stack *top, char name)
{
	while (*head != top)
	{
		if (name == 'a')
		{
			if (top->above)
				ra(head, false);
			else
				rra(head, false);
		}
		else if (name == 'b')
		{
			if (top->above)
				rb(head, false);
			else
				rrb(head, false);
		}
	}
}
