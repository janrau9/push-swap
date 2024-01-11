/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:06:18 by jberay            #+#    #+#             */
/*   Updated: 2024/01/11 08:11:10 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	check_seq(t_stack *head, int i)
{
	t_stack	*ptr;

	ptr = ps_lstlast(head);
	while (ptr)
	{
		if (ptr->lis == i)
		{
			ptr->leave = true;
			i--;
		}
		ptr = ptr->prev;
	}
}

static int	lis_max(t_stack *head)
{
	long	max;
	t_stack	*hold;

	max = LONG_MIN;
	while (head)
	{
		if (head->lis > max)
		{
			max = head->lis;
			hold = head;
		}
		head = head->next;
	}
	return (hold->lis);
}

void	lis(t_stack **head)
{
	t_stack	*ptri;
	t_stack	*ptrj;

	ptrj = *head;
	ptri = (ptrj)->next;
	while (ptri)
	{
		ptrj = *head;
		while (ptrj != ptri)
		{
			if (ptri->final_pos > ptrj->final_pos)
			{
				if (ptrj->lis + 1 > ptri->lis)
					ptri->lis = ptrj->lis + 1;
			}
			ptrj = ptrj->next;
		}
		ptri = ptri->next;
	}
	check_seq(*head, lis_max(*head));
}
