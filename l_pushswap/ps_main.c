/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:40:13 by jberay            #+#    #+#             */
/*   Updated: 2024/01/18 11:17:04 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pushswap.h"

static void	call_sort(t_stack **a_head, t_stack **b_head)
{
	sort_final_pos(a_head);
	if (!sorted(*a_head))
	{
		if (ps_lstsize(*a_head) == 2)
			sa(a_head, false);
		else if (ps_lstsize(*a_head) == 3)
			sort_three(a_head);
		else if (ps_lstsize(*a_head) <= 5)
			sort_five(a_head, b_head);
		else
			sort_big(a_head, b_head);
	}
}

static char	*call_join(char **argv)
{
	char	*temp;
	char	*temp1;
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (argv[++i])
	{
		temp1 = str;
		temp = ft_strjoin(argv[i], " ");
		if (!temp)
		{
			free(temp1);
			return (NULL);
		}
		str = ft_strjoin(temp1, temp);
		if (!str)
			ft_free(temp, temp1);
		free(temp);
		free(temp1);
	}
	return (str);
}

int	main(int argc, char **argv)
{
	t_stack	*a_head;
	t_stack	*b_head;
	char	*str;

	a_head = NULL;
	b_head = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	str = call_join(argv);
	if (!str)
		return (1);
	argv = ft_split(str, ' ');
	if (argv == NULL)
		return (1);
	free(str);
	initialize(&a_head, argv);
	call_sort(&a_head, &b_head);
	ps_lstclear(&a_head);
	return (0);
}
