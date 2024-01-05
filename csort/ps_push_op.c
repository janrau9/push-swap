/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 07:29:36 by jberay            #+#    #+#             */
/*   Updated: 2023/12/14 07:30:05 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * push steps
 * if b not empty
 * b1.prev = a1
 * a1 = a2
 * a1.next = b1
 * b1 = a1
 * 
 * if b is empty
 * b1 = a1
 * a1 = a2
 * b1.next = 0
 */

static void	push(t_stack **get_from, t_stack **push_to)
{
	if (*push_to != NULL)
	{
		(*push_to)->prev = *get_from;
		*get_from = (*get_from)->next;
		(*push_to)->prev->next = *push_to;
		*push_to = (*push_to)->prev;
	}
	else
	{
		*push_to = *get_from;
		*get_from = (*get_from)->next;
		(*push_to)->next = NULL;
		(*push_to)->prev = NULL;
	}
}

void	pa(t_stack **a_head, t_stack **b_head)
{
	push(b_head, a_head);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a_head, t_stack **b_head)
{
	push(a_head, b_head);
	write(1, "pb\n", 3);
}