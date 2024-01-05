/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:59:58 by jberay            #+#    #+#             */
/*   Updated: 2023/12/20 09:12:46 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ps_lstclear(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*temp;

	if (lst)
	{
		ptr = *lst;
		while (ptr != NULL)
		{
			temp = ptr;
			ptr = ptr->next;
			free(temp);
		}
		*lst = NULL;
	}
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	if (*argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

int	ps_error(t_stack **head, char **argv, int flag)
{
	ps_lstclear(head);
	if (flag == 1)
		free_split(argv);
	write(2, "Error\n", 6);
	return (0);
}
