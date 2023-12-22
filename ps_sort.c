/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:30:36 by jberay            #+#    #+#             */
/*   Updated: 2023/12/22 11:40:48 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*helper for sort_three*/
static t_stack	*find_highest(t_stack *ptr)
{
	int		highest;
	t_stack	*hold;

	highest = INT_MIN;
	while (ptr != NULL)
	{
		if (ptr->final_pos > highest)
		{
			highest = ptr->final_pos;
			hold = ptr;
		}
		ptr = ptr->next;
	}
	return (hold);
}

void	sort_three(t_stack **head)
{
	t_stack	*hold;

	hold = find_highest(*head);
	if (*head == hold)
		ra(head);
	else if ((*head)->next == hold)
		rra(head);
	if ((*head)->final_pos > (*head)->next->final_pos)
		sa(head);
}


static int	sorted(t_stack **head)
{
	t_stack	*ptr;

	ptr = *head;
	while (ptr->next)
	{
		if (ptr->final_pos != ptr->next->final_pos - 1)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	sort_big_a(t_stack **a_head, t_stack **b_head, int max_num)
{
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	max_bits = 0;
	printf("%d \n", ps_lstsize(*a_head));
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (!sorted(a_head))
	{
		j = 0;
		while (j < (max_num + 1))
		{
			if (((((*a_head)->final_pos) >> i) & 1) == 1)
				ra(a_head);
			else
				pb(a_head, b_head);
			j++;
		}
		while (ps_lstsize(*a_head) != max_num + 1)
			pa(a_head, b_head);
		i++;
	}
}

void	sort_big_b(t_stack **a_head, t_stack **b_head, int max_num)
{
	int	max_bits;
	int	i;
	int	j;

	i = -1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < max_num + 1)
		{
			if (((((*b_head)->final_pos) >> i) & 1) == 1)
				pa(a_head, b_head);
			else
				rb(b_head);
		}
		while (ps_lstsize(*b_head) != max_num + 1)
			pb(a_head, b_head);
	}
}
