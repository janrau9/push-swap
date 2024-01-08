/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:40:56 by jberay            #+#    #+#             */
/*   Updated: 2024/01/08 14:09:39 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	find_btoa(t_stack *a_head, t_stack *b_head)
{
	t_stack	*hold;
	t_stack	*target;
	long	match_index;

	while (b_head)
	{
		match_index = LONG_MAX;
		hold = a_head;
		while (hold)
		{
			if (hold->final_pos > b_head->final_pos
				&& hold->final_pos < match_index)
			{
				match_index = hold->final_pos;
				target = hold;
			}
			hold = hold->next;
		}
		if (match_index == LONG_MAX)
			b_head->target = find_min(a_head);
		else
			b_head->target = target;
		b_head = b_head->next;
	}
}

void	current_index(t_stack *head)
{
	int	i;
	int	median;

	i = 0;
	if (!head)
		return ;
	median = ps_lstsize(head) / 2;
	while (head)
	{
		head->index = i;
		if (i <= median)
			head->above = true;
		else
			head->above = false;
		head = head->next;
		i++;
	}
}

void	cost(t_stack *a_head, t_stack *b_head)
{
	int	size_a;
	int	size_b;

	size_a = ps_lstsize(a_head);
	size_b = ps_lstsize(b_head);
	while (b_head)
	{
		b_head->push_cost = b_head->index;
		if (!(b_head->above))
			b_head->push_cost = size_b - (b_head->index);
		if (b_head->target->above)
			b_head->push_cost = b_head->push_cost + b_head->target->index;
		else
			b_head->push_cost += size_a - b_head->target->index;
		b_head = b_head->next;
	}
}

void	cheapest(t_stack *head, int size, int j)
{
	long	cheapest;
	t_stack	*hold;

	if (!head)
		return ;
	cheapest = LONG_MAX;
	while (head)
	{
		if (head->push_cost < cheapest
			&& head->final_pos / size == j)
		{
			cheapest = head->push_cost;
			hold = head;
		}
		head = head->next;
	}
	hold->cheapest = true;
}

void	init_b(t_stack *a_head, t_stack *b_head, int size)
{
	int	chunk;
	int	j;

	current_index(a_head);
	current_index(b_head);
	find_btoa(a_head, b_head);
	cost(a_head, b_head);
	chunk = chunk_size(size);
	j = (ps_lstsize(b_head) - 1) / chunk;
	cheapest(b_head, chunk, j);
}
