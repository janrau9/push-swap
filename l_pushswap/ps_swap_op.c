/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:38:12 by jberay            #+#    #+#             */
/*   Updated: 2024/01/08 09:45:51 by jberay           ###   ########.fr       */
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
	int	size;

	size = ps_lstsize(*head);
	if (size == 1 || *head == NULL)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a_head, bool print)
{
	swap(a_head);
	if (!print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b_head, bool print)
{
	swap(b_head);
	if (!print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a_head, t_stack **b_head, bool print)
{
	swap(a_head);
	swap(b_head);
	if (!print)
		write(1, "ss\n", 3);
}
