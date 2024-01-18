/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:51:59 by vsavolai          #+#    #+#             */
/*   Updated: 2023/11/10 09:12:19 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nlen(int n)
{
	size_t	nlen;

	if (n == -2147483648)
	{
		nlen = 12;
		return (nlen);
	}
	nlen = 1;
	if (n < 0)
	{
		nlen++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		nlen++;
	}
	return (nlen + 1);
}

static char	*ft_putnbr(long n, char *r, size_t rlen)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		*r = '-';
		n *= -1;
		i++;
	}
	rlen--;
	r[rlen] = '\0';
	while (rlen > i)
	{
		rlen--;
		r[rlen] = (n % 10) + '0';
		n /= 10;
	}
	return (r);
}

char	*ft_itoa(int nb)
{
	size_t	rlen;
	char	*r;
	long	n;

	n = nb;
	rlen = ft_nlen(n);
	r = malloc(sizeof(char) * rlen);
	if (r == 0)
		return (0);
	ft_putnbr(n, r, rlen);
	return (r);
}
