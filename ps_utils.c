/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:17:37 by jberay            #+#    #+#             */
/*   Updated: 2023/12/21 11:40:55 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// static long	dec_bin(int dec_nbr)
// {
// 	int	bin_nbr;
// 	int	i;
// 	int	remainder;

// 	bin_nbr = 0;
// 	i = 1;
// 	while (dec_nbr != 0)
// 	{
// 		remainder = dec_nbr % 2;
// 		dec_nbr = dec_nbr / 2;
// 		bin_nbr = bin_nbr + remainder * i;
// 		i = i * 10;
// 	}
// 	return (bin_nbr);
// }

void	add_chunk_index(t_stack **head, int max)
{
	t_stack	*ptr;

	ptr = *head;
	while (ptr)
	{
		if (ptr->final_pos < max)
			ptr->chunk_pos = ptr->final_pos;
		else if (ptr->final_pos >= max && ptr->final_pos < max * 2)
			ptr->chunk_pos = ptr->final_pos - max;
		else if (ptr->final_pos >= max * 2 && ptr->final_pos < max * 3)
			ptr->chunk_pos = ptr->final_pos - max * 2;
		else if (ptr->final_pos >= max * 3)
			ptr->chunk_pos = ptr->final_pos - max * 3;
		ptr = ptr->next;
	}
}

static void	split_to_three(t_stack **a_head, t_stack **b_head, int size)
{
	while (ps_lstsize(*b_head) < 2)
	{
		if ((*a_head)->final_pos < size)
			pb(a_head, b_head);
		else if (((*a_head)->final_pos >= size)
			&& ((*a_head)->final_pos < size * 2))
			pb(a_head, b_head);
		else
			ra(a_head);
	}
	if ((*b_head)->final_pos < (*b_head)->next->final_pos)
		sb(b_head);
	while (ps_lstsize(*b_head) < size * 2)
	{
		if ((*a_head)->final_pos < size)
		{
			pb(a_head, b_head);
			rb(b_head);
		}
		else if (((*a_head)->final_pos >= size)
			&& ((*a_head)->final_pos < size * 2))
			pb(a_head, b_head);
		else
			ra(a_head);
	}
}

void	split_to_chunks(t_stack **a_head, t_stack **b_head)
{
	int	size;

	size = ps_lstsize(*a_head) / 4;
	split_to_three(a_head, b_head, size);
	while (ps_lstsize(*b_head) < size * 3)
	{
		if (((*a_head)->final_pos >= size * 2)
			&& ((*a_head)->final_pos < size * 3))
			pb(a_head, b_head);
		else
			ra(a_head);
	}
	add_chunk_index(a_head, size);
	add_chunk_index(b_head, size);
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