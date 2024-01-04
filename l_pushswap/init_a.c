/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:31:28 by jberay            #+#    #+#             */
/*   Updated: 2024/01/04 13:03:13 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	find_atob(t_stack *a_head, t_stack *b_head)
{
	t_stack	*hold;
	t_stack	*target;
	long	match_index;

	while (a_head)
	{
		match_index = LONG_MIN;
		hold = b_head;
		while (hold)
		{
			if (hold->final_pos < a_head->final_pos
				&& hold->final_pos > match_index)
			{
				match_index = hold->final_pos;
				target = hold;
			}
			hold = hold->next;
		}
		if (match_index == LONG_MIN)
			a_head->target = find_max(b_head);
		else
			a_head->target = target;
		a_head = a_head->next;
	}
}

void	init_a(t_stack *a_head, t_stack *b_head)
{
	current_index(a_head);
	current_index(b_head);
	find_atob(a_head, b_head);
	cost(b_head, a_head);
	cheapest(a_head);
}

