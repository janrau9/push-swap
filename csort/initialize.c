/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:06:55 by jberay            #+#    #+#             */
/*   Updated: 2023/12/28 09:44:04 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft/libft.h"

void	initialize(t_stack **a_head, char **argv, int i, int is_split)
{
	long	element;
	t_stack	*a_temp;

	while (argv[i])
	{
		element = ps_atoi(*a_head, argv[i]);
		if (element < INT_MIN || element > INT_MAX)
			ps_error(a_head, argv, is_split);
		a_temp = ps_lstnew((int)element);
		if (a_temp == NULL)
			ps_error(a_head, argv, is_split);
		ps_lstadd_back(a_head, a_temp);
		i++;
	}
	if (is_split == 1)
		free_split(argv);
}