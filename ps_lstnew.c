/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:38:09 by jberay            #+#    #+#             */
/*   Updated: 2023/12/20 12:49:55 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// static void	check_final_pos(t_stack **head, int content)
// {
// 	while (head != NULL)
// 	{	
// 		if ((*head)->prev == NULL)
// 			*head = (*head)->next;
// 		if ((*head)->prev->element < content
// 			&& (*head)->element > content)
// 				insert
// 		if ((*head)->prev->element > content
// 			&& (*head)->element < content)
// 	}
// }

t_stack	*ps_lstnew(int content)
{
	t_stack	*plst;

	plst = malloc(sizeof(t_stack));
	if (!plst)
		return (NULL);
	plst->element = content;
	plst->next = NULL;
	plst->prev = NULL;
	plst->final_pos = -1;
	// check_final_pos(head, content);
	return (plst);
}
