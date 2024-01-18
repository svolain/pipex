/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:31:15 by vsavolai          #+#    #+#             */
/*   Updated: 2024/01/04 12:54:35 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_format(char specifier, va_list al)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(al, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(al, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_digit((long)(va_arg(al, int)), 10, specifier);
	else if (specifier == 'u')
		count += ft_print_digit((long)(va_arg(al, unsigned int)), 10,
				specifier);
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_digit((long)(va_arg(al, unsigned int)), 16,
				specifier);
	else if (specifier == 'p')
		count += ft_print_pointer((unsigned long)(va_arg(al, void *)));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	al;
	int		count;
	int		flag;

	va_start(al, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			flag = ft_print_format(*(++format), al);
		else if ((' ' >= *format || *format <= '~')
			|| ('\t' >= *format || *format <= '\r'))
			flag = write(1, format, 1);
		else
			count ++;
		if (flag < 0)
			return (-1);
		count += flag;
		format++;
	}
	va_end(al);
	return (count);
}
