/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:39:39 by jberay            #+#    #+#             */
/*   Updated: 2024/01/08 09:58:17 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push(t_stack **get_from, t_stack **push_to)
{
	if (*get_from == NULL)
		return ;
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

void	pa(t_stack **a_head, t_stack **b_head, bool print)
{
	push(b_head, a_head);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a_head, t_stack **b_head, bool print)
{
	push(a_head, b_head);
	if (!print)
		write(1, "pb\n", 3);
}
