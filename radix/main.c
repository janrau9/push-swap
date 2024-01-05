/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:07:29 by jberay            #+#    #+#             */
/*   Updated: 2023/12/22 15:34:14 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack	*a_temp;
	long	element;
	int		i;
	int		flag;
	int		size;

	a_head = NULL;
	b_head = NULL;
	i = 1;
	flag = 0;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (argv[1][0] == 0)
		{
			write(2, "Error", 6);
			return (1);
		}
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (0);
		i = 0;
		flag = 1;
	}
	while (argv[i])
	{
		element = ps_atoi(a_head, argv[i]);
		if (element < INT_MIN || element > INT_MAX)
			return (ps_error(&a_head, argv, flag));
		a_temp = ps_lstnew((int)element);
		if (a_temp == NULL)
			return (ps_error(&a_head, argv, flag));
		ps_lstadd_back(&a_head, a_temp);
		argc--;
		i++;
	}
	if (flag == 1)
		free_split(argv);
	sort_final_pos(&a_head);
	size = ps_lstsize(a_head);
	if (ps_lstsize(a_head) == 3)
		sort_three(&a_head);
	else if (ps_lstsize(a_head) == 5)
	{
		split_stack(&a_head, &b_head);
		add_stack_index(&a_head, size);
		add_stack_index(&b_head, size);
		if ((b_head)->final_pos < (b_head)->next->final_pos)
			sb(&b_head);
		sort_three(&a_head);
		while (ps_lstsize(b_head))
			pa(&a_head, &b_head);
	}
	else
	{
		split_stack(&a_head, &b_head);
		add_stack_index(&a_head, size);
		add_stack_index(&b_head, size);
		sort_big_a(&a_head, &b_head, ps_lstsize(a_head) - 1);
		sort_big_b(&a_head, &b_head, ps_lstsize(b_head) - 1);
		while (ps_lstsize(b_head))
			pa(&a_head, &b_head);
	}
	//error check if node is 1

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
	ps_lstclear(&a_head);
}



