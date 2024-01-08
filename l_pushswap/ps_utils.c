/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:37:24 by jberay            #+#    #+#             */
/*   Updated: 2024/01/05 11:37:26 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_final_pos(t_stack **head)
{
	t_stack	*ptr;
	t_stack	*hold;
	int		index;
	long	nbr;

	ptr = *head;
	index = 0;
	while (index < ps_lstsize(*head))
	{
		nbr = LONG_MAX;
		while (ptr != NULL)
		{
			if (ptr->element < nbr && ptr->final_pos == -1)
			{
				nbr = ptr->element;
				hold = ptr;
			}
			ptr = ptr->next;
		}
		ptr = *head;
		hold->final_pos = index++;
	}
}

t_stack	*find_max(t_stack *head)
{
	long	max;
	t_stack	*hold;

	if (!head)
		return (NULL);
	max = LONG_MIN;
	while (head)
	{
		if (head->final_pos > max)
		{
			max = head->final_pos;
			hold = head;
		}
		head = head->next;
	}
	return (hold);
}

t_stack	*find_min(t_stack *head)
{
	long	min;
	t_stack	*hold;

	if (!head)
		return (NULL);
	min = LONG_MAX;
	while (head)
	{
		if (head->final_pos < min)
		{
			min = head->final_pos;
			hold = head;
		}
		head = head->next;
	}
	return (hold);
}

t_stack	*get_cheapest(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->cheapest)
			return (head);
		head = head->next;
	}
	return (NULL);
}

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
