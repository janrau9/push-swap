/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 07:26:41 by jberay            #+#    #+#             */
/*   Updated: 2023/12/20 07:46:08 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/**
 * swap steps
 * head = n2
 * n1.prev = n2
 * n1.next = n2.next
 * n3 = n2.prev
 * n2.next = n1
 * n2.prev = n0
 */

static void	swap(t_stack **head)
{
	if (ps_lstsize(*head) > 1 || *head != NULL)
	{
		*head = (*head)->next;
		(*head)->prev->prev = *head;
		(*head)->prev->next = (*head)->next;
		if ((*head)->next)
			(*head)->next->prev = (*head)->prev;
		(*head)->next = (*head)->prev;
		(*head)->prev = NULL;
	}
}

void	sa(t_stack **a_head)
{
	swap(a_head);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b_head)
{
	swap(b_head);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a_head, t_stack **b_head)
{
	swap(a_head);
	swap(b_head);
	write(1, "ss\n", 3);
}