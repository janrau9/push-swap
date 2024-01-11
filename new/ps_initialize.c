/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:24:05 by jberay            #+#    #+#             */
/*   Updated: 2024/01/08 14:24:06 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	check_dup(t_stack *head, long result)
{
	while (head != NULL)
	{
		if (result == head->element)
			return (1);
		head = head->next;
	}
	return (0);
}

long	ps_atoi(t_stack *head, const char *str)
{
	unsigned long long	result;
	int					sign;
	int					check_digit;

	sign = 1;
	result = 0;
	check_digit = 0;
	if (*str == '\0')
		return (2147483649);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str >= 0) && (*str == '-' || *str == '+'))
		str++;
	while ((*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
		check_digit = 1;
	}
	if ((!(*str >= '0' && *str <= '9') && *str != '\0')
		|| check_digit == 0 || check_dup(head, (long)result * sign) == 1)
		return (2147483649);
	return ((long)result * sign);
}

void	initialize(t_stack **a_head, char **argv, int i)
{
	long	element;
	t_stack	*a_temp;
	int		is_split;

	is_split = i;
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
	if (is_split == 0)
		free_split(argv);
}
