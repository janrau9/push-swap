/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:07:29 by jberay            #+#    #+#             */
/*   Updated: 2024/01/04 16:02:40 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*a_head;
	t_stack	*b_head;
	int		i;
	int		is_split;

	a_head = NULL;
	b_head = NULL;
	i = 1;
	is_split = 0;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		if (argv[1][0] == 0)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			exit (1);
		i = 0;
		is_split = 1;
	}
	initialize(&a_head, argv, i, is_split);
	sort_final_pos(&a_head);

	if (!sorted(a_head))
	{
		if (ps_lstsize(a_head) == 2)
			sa(&a_head);
		else if (ps_lstsize(a_head) == 3)
			sort_three(&a_head);
		else if (ps_lstsize(a_head) <= 5)
			sort_five(&a_head, &b_head);
		else
			sort_big(&a_head, &b_head);
	}
	ps_lstclear(&a_head);
	return (0);
}



