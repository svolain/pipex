/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 07:16:17 by vsavolai          #+#    #+#             */
/*   Updated: 2023/11/10 10:35:41 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_limits(long n, long flag)
{
	if (n < 0 && flag > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long			n;
	int				i;
	int				flag;

	n = 0;
	i = 0;
	flag = 1;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (n < 0)
		return (ft_check_limits(n, flag));
	return (flag * n);
}
