/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:30:36 by jberay            #+#    #+#             */
/*   Updated: 2023/12/22 09:47:33 by jberay           ###   ########.fr       */
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


// static int	sorted(t_stack **head)
// {
// 	t_stack	*ptr;

// 	ptr = *head;
// 	while (ptr->next)
// 	{
// 		if (ptr->final_pos != ptr->next->final_pos - 1)
// 			return (0);
// 		ptr = ptr->next;
// 	}
// 	return (1);
// }


static void	set_rotation(t_stack **head)
{
	int		i;
	int		centerline;
	t_stack	*ptr;

	i = 0;
	ptr = *head;
	centerline = ps_lstsize(ptr) / 2;
	while (ptr)
	{
		if (i <= centerline)
		{
			ptr->above = true;
			ptr->index = i;
		}
		else
		{
			ptr->above = false;
			ptr->index = centerline * 2 - i;
		}
		ptr = ptr->next;
		++i;
	}
}

static t_stack	*rotate(t_stack *head, int i, char name)
{
	t_stack	*ptr;
	t_stack	*hold;
	long	min;
	int		call;

	set_rotation(&head);
	ptr = head;
	min = INT_MAX;
	while (ptr)
	{
		if ((((ptr->chunk_pos) >> i) & 1) == 1 && ptr->index < min)
		{
			hold = ptr;
			min = ptr->index;
		}
		ptr = ptr->next;
	}
	call = hold->index;
	printf("%d %d \n", hold->index, hold->final_pos);
	if (hold->above == true)
	{

			if (name == 'a')
				ra(&head);
			else
				rb(&head);
			call--;
	}
	if (hold->above == false)
	{
		
			if (name == 'a')
				rra(&head);
			else
				rrb(&head);
			call--;
	}
	return (head);
}

void	sort_big_a(t_stack **a_head, t_stack **b_head, int max_num)
{
	int	max_bits;
	int	i;
	int	j;
	t_stack	*temp;

	i = -1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < max_num + 1)
		{
			temp = *a_head;
			*a_head = rotate(temp, i, 'a');
			pb(a_head, b_head);
		}
		while (ps_lstsize(*a_head) != max_num + 1)
			pa(a_head, b_head);
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
			if (((((*b_head)->chunk_pos) >> i) & 1) == 1)
				pa(a_head, b_head);
			else
				rb(b_head);
		}
		while (ps_lstsize(*b_head) != max_num + 1)
			pb(a_head, b_head);
	}
}
