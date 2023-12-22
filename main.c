/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:07:29 by jberay            #+#    #+#             */
/*   Updated: 2023/12/22 09:32:28 by jberay           ###   ########.fr       */
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

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
	{
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
	// else if (ps_lstsize(a_head) <= 5)
	// {
	// 	add_chunk_index(&a_head, ps_lstsize(a_head));
	// 	sort_big_a(&a_head, &b_head, size);
	// }
	else
	{
		// split_stack(&a_head, &b_head);
		add_stack_index(&a_head, size);
		add_stack_index(&b_head, size);
		sort_big_a(&a_head, &b_head, ps_lstsize(a_head) - 1);
		// sort_big_b(&a_head, &b_head, ps_lstsize(b_head) - 1);
		while (ps_lstsize(b_head))
			pa(&a_head, &b_head);
		// while (ps_lstsize(b_head))
		// 	pa(&a_head, &b_head);
		// split_to_chunks(&a_head, &b_head);
	}
	//error check if node is 1

	while (a_head != NULL)
	{
	
		printf("A - %d | out - %d | A - %d | C - %d \n", a_head->element, a_head->final_pos, a_head->element, a_head->chunk_pos);
		a_head = a_head->next;
	}
	while (b_head != NULL)
	{
		printf("B - %d | out - %d | B - %d | C - %d \n", b_head->element, b_head->final_pos, b_head->element, b_head->chunk_pos);
		b_head = b_head->next;
	}
}



