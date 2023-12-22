/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:17:37 by jberay            #+#    #+#             */
/*   Updated: 2023/12/22 07:06:44 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_stack_index(t_stack **head, int max_num)
{
	t_stack	*ptr;

	ptr = *head;
	while (ptr)
	{
		if (ptr->final_pos < max_num / 2)
			ptr->chunk_pos = ptr->final_pos;
		else if (ptr->final_pos >= max_num / 2)
			ptr->chunk_pos = ptr->final_pos - (max_num / 2);
		ptr = ptr->next;
	}
}

void	split_stack(t_stack **a_head, t_stack **b_head)
{
	int	size;

	size = ps_lstsize(*a_head);
	while (ps_lstsize(*b_head) != size / 2)
	{
		if ((*a_head)->final_pos < size / 2)
			pb(a_head, b_head);
		else
			ra(a_head);
	}
}

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


t_stack	*find_last_head(t_stack **head)
{
	t_stack	*ptr;

	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

int	check_b_revsorted(t_stack **head)
{
	t_stack	*ptr;

	ptr = *head;
	while (ptr->next != NULL)
	{
		if ((ptr->final_pos) != ptr->next->final_pos - 1)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}