/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:15:45 by vsavolai          #+#    #+#             */
/*   Updated: 2023/11/10 09:18:54 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (dstsize == 0)
		return (ft_strlen(src));
	k = ft_strlen(dst);
	i = 0;
	j = ft_strlen(dst);
	while (j < (dstsize - 1) && src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	if (dstsize < j)
		return (dstsize + ft_strlen(src));
	else
		return (k + ft_strlen(src));
}
