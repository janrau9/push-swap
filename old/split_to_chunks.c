/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:15:16 by jberay            #+#    #+#             */
/*   Updated: 2024/01/11 08:15:17 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sorted(t_stack *head)
{
	t_stack	*ptr;

	ptr = head;
	while (ptr->next)
	{
		if (ptr->final_pos > ptr->next->final_pos)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

static void	mark_group(t_stack **head, int ch_size)
{
	t_stack	*ptr;
	int		i;
	long	nbr;

	ptr = *head;
	i = 0;
	while (ps_lstsize(*head) / ch_size >= i)
	{
		nbr = LONG_MAX;
		while (ptr != NULL)
		{
			if (ptr->group == -1 && ptr->final_pos / ch_size == i)
			{
				ptr->group = i;
			}
			ptr = ptr->next;
		}
		ptr = *head;
		i++;
	}
}

static bool	next_loop(t_stack **head, int i)
{
	t_stack	*ptr;

	ptr = *head;
	while (ptr)
	{
		if (!ptr->leave && (ptr->group == i || ptr->group == i + 1))
			return (false);
		ptr = ptr->next;
	}
	return (true);
}

void	split_to_chunks(t_stack **a_head, t_stack **b_head, int size)
{
	int	ch_size;
	int	i;
	int	j;

	ch_size = chunk_size(size);
	mark_group(a_head, ch_size);
	i = 0;
	j = 1;
	while (ps_lstsize(*a_head) > 3 && !sorted(*a_head))
	{
		if (((*a_head)->group == i || (*a_head)->group == i + 1)
			&& !(*a_head)->leave)
		{
			pb(a_head, b_head, false);
			if ((*b_head)->group == i + 1)
				rb(b_head, false);
		}
		else
			ra(a_head, false);
		if (next_loop(a_head, i))
		{
			i = i + 2;
			j++;
		}
	}
}
