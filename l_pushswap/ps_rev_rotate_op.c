/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:38:56 by jberay            #+#    #+#             */
/*   Updated: 2024/01/05 12:17:50 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rev_rotate(t_stack **head)
{
	t_stack	*last;
	int		size;

	size = ps_lstsize(*head);
	if (*head == NULL || size == 1)
		return ;
	last = ps_lstlast(*head);
	last->prev->next = NULL;
	last->next = *head;
	last->prev = NULL;
	*head = last;
	last->next->prev = last;
}

void	rra(t_stack **head, bool print)
{
	rev_rotate(head);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **head, bool print)
{
	rev_rotate(head);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a_head, t_stack **b_head, bool print)
{
	rev_rotate(a_head);
	rev_rotate(b_head);
	if (!print)
		write(1, "rrr\n", 4);
}
