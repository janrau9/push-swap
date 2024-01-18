/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:06:43 by jberay            #+#    #+#             */
/*   Updated: 2024/01/18 11:07:04 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ps_lstclear(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*temp;

	if (*lst == NULL)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	*lst = NULL;
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	if (*argv == NULL || argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

int	ps_error(t_stack **head, char **argv)
{
	ps_lstclear(head);
	free_split(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(char *tmp, char *tmp1)
{
	free(tmp);
	free(tmp1);
	exit (1);
}
