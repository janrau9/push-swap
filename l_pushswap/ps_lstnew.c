/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:38:09 by jberay            #+#    #+#             */
/*   Updated: 2024/01/05 07:44:11 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	plst->index = -1;
	plst->target = NULL;
	return (plst);
}
