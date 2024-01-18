/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 05:56:39 by vsavolai          #+#    #+#             */
/*   Updated: 2023/11/09 14:25:30 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n)
{
	unsigned char	*cbuf;
	size_t			i;

	cbuf = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		if (*cbuf == (unsigned char)c)
		{
			return (cbuf);
		}
		cbuf++;
		i++;
	}
	return (NULL);
}
