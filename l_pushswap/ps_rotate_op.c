/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:38:35 by jberay            #+#    #+#             */
/*   Updated: 2024/01/05 12:18:34 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * rotate steps
 * nlast.next = n1 == head
 * head = n1.next == n2
 * n2.prev = 0
 * n1 .prev = nlast
 * n2.next = 0 
 */
static void	rotate(t_stack **head)
{
	t_stack	*last;
	int		size;

	size = ps_lstsize(*head);
	if (*head == NULL || size == 1)
		return ;
	last = ps_lstlast(*head);
	last->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack **head, bool print)
{
	rotate(head);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **head, bool print)
{
	rotate(head);
	if (!print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a_head, t_stack **b_head, bool print)
{
	rotate(a_head);
	rotate(b_head);
	if (!print)
		write(1, "rr\n", 3);
}
