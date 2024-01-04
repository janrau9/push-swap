/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:07:29 by jberay            #+#    #+#             */
/*   Updated: 2024/01/04 13:32:57 by jberay           ###   ########.fr       */
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
			write(2, "Error", 6);
			return (1);
		}
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (1);
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
	// while (a_head != NULL)
	// {
	
	// 	printf("A - %d | out - %d || index - %d\n", a_head->element, a_head->final_pos, a_head->index);
	// 	a_head = a_head->next;
	// }
	// while (b_head != NULL)
	// {
	// 	printf("B - %d | out - %d || index - %d\n", b_head->element, b_head->final_pos, b_head->index);
	// 	b_head = b_head->next;
	// }
	// ps_lstclear(&a_head);
	// return (0);
	ps_lstclear(&a_head);
}



