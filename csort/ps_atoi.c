/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:40:59 by jberay            #+#    #+#             */
/*   Updated: 2023/12/20 09:56:09 by jberay           ###   ########.fr       */
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

