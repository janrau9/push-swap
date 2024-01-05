/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 07:30:31 by jberay            #+#    #+#             */
/*   Updated: 2023/12/20 07:50:42 by jberay           ###   ########.fr       */
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

void	rra(t_stack **head)
{
	rev_rotate(head);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **head)
{
	rev_rotate(head);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a_head, t_stack **b_head)
{
	rev_rotate(a_head);
	rev_rotate(b_head);
	write(1, "rrr\n", 4);
}