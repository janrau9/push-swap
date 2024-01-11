/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:05:42 by jberay            #+#    #+#             */
/*   Updated: 2024/01/08 14:27:50 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	on_error(t_stack **a, t_stack **b)
{
	ps_lstclear(a);
	ps_lstclear(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_command(t_stack **a_head, t_stack **b_head, char *command)
{
	if (!ft_strncmp(command, "pa\n", ft_strlen(command)))
		pa(a_head, b_head, true);
	else if (!ft_strncmp(command, "pb\n", ft_strlen(command)))
		pb(a_head, b_head, true);
	else if (!ft_strncmp(command, "sa\n", ft_strlen(command)))
		sa(a_head, true);
	else if (!ft_strncmp(command, "sb\n", ft_strlen(command)))
		sb(b_head, true);
	else if (!ft_strncmp(command, "ss\n", ft_strlen(command)))
		ss(a_head, b_head, true);
	else if (!ft_strncmp(command, "ra\n", ft_strlen(command)))
		ra(a_head, true);
	else if (!ft_strncmp(command, "rb\n", ft_strlen(command)))
		rb(b_head, true);
	else if (!ft_strncmp(command, "rr\n", ft_strlen(command)))
		rr(a_head, b_head, true);
	else if (!ft_strncmp(command, "rra\n", ft_strlen(command)))
		rra(a_head, true);
	else if (!ft_strncmp(command, "rrb\n", ft_strlen(command)))
		rrb(b_head, true);
	else if (!ft_strncmp(command, "rrr\n", ft_strlen(command)))
		rrr(a_head, b_head, true);
	else
		on_error(a_head, b_head);
}

static void	call_next_line(t_stack **a_head, t_stack **b_head)
{
	char	*next_line;
	int		size;

	size = ps_lstsize(*a_head);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_command(a_head, b_head, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (sorted(*a_head) && ps_lstsize(*a_head) == size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a_head;
	t_stack	*b_head;
	int		i;

	a_head = NULL;
	b_head = NULL;
	i = 1;
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
	}
	initialize(&a_head, argv, i);
	call_next_line(&a_head, &b_head);
	ps_lstclear(&a_head);
}
