/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:59:41 by jberay            #+#    #+#             */
/*   Updated: 2024/01/08 10:13:13 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	chunk_size(int size)
{
	int	ch_size;

	if (size <= 100)
		ch_size = 33;
	else
		ch_size = 70;
	return (ch_size);
}

void	split_to_chunks(t_stack **a_head, t_stack **b_head, int i, int j)
{
	int	size;

	size = chunk_size(ps_lstsize(*a_head));
	while (*a_head && ps_lstsize(*b_head) < (i * 2 * size))
	{
		if ((*a_head)->final_pos / size == j + 1)
		{
			pb(a_head, b_head, false);
		}
		else if ((*a_head)->final_pos / size == j)
		{
			pb(a_head, b_head, false);
			rb(b_head, false);
		}
		else
			ra(a_head, false);
	}
}

void	split_to_chunks_one(t_stack **a_head, t_stack **b_head, int i, int j)
{
	int	size;
	int	rr;

	rr = 0;
	size = chunk_size(ps_lstsize(*a_head));
	while (*a_head && ps_lstsize(*b_head) < (i * 2 * size))
	{
		if ((*a_head)->final_pos / size == j)
		{
			pb(a_head, b_head, false);
		}
		else if ((*a_head)->final_pos / size == j + 1)
		{
			pb(a_head, b_head, false);
			rb(b_head, false);
			rr++;
		}
		else
			ra(a_head, false);
	}
	while (rr > 0)
	{
		rrb(b_head, false);
		rr--;
	}
}
