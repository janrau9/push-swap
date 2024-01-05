/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:59:41 by jberay            #+#    #+#             */
/*   Updated: 2024/01/04 15:21:45 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	chunk(int nbr, int size)
{
	int	chunk;

	chunk = nbr / size;
	return (chunk);
}

static int	chunk_size(int size)
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
		if (chunk((*a_head)->final_pos, size) == j)
		{
			pb(a_head, b_head);
		}
		else if (chunk((*a_head)->final_pos, size) == j + 1)
		{
			pb(a_head, b_head);
			rb(b_head);
		}
		else
			ra(a_head);
	}
}