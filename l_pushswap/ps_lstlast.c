/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:01:54 by jberay            #+#    #+#             */
/*   Updated: 2023/12/11 09:54:30 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ps_lstlast(t_stack *lst)
{
	t_stack	*ptr;

	ptr = lst;
	if (ptr)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		return (ptr);
	}
	return (NULL);
}
