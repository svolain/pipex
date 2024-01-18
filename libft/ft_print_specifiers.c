/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:36:47 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/04 12:54:28 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	count;
	int	flag;

	if (!str)
	{
		flag = write(1, "(null)", 6);
		if (flag < 0)
			return (-1);
		return (6);
	}
	count = 0;
	while (*str != '\0')
	{
		flag = ft_print_char((int)*str);
		if (flag < 0)
			return (-1);
		count += flag;
		str++;
	}
	return (count);
}

int	ft_print_digit(long n, int base, char specifier)
{
	int		count;
	char	*symbols;

	if (specifier == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		return (ft_print_digit((n * -1), base, specifier) + 1);
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		count = ft_print_digit(n / base, base, specifier);
		if (count < 0)
			return (-1);
		return (count + ft_print_digit(n % base, base, specifier));
	}
}

int	ft_print_pointer(unsigned long n)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	count += write(1, "0x", 2);
	if (count < 0)
		return (-1);
	if (n < 16)
	{
		count += ft_print_char(symbols[n]);
		return (count);
	}
	count += (ft_print_digit((n / 16), 16, 'x'));
	return (count + ft_print_digit(n % 16, 16, 'x'));
}
