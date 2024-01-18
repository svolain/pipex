/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 06:19:34 by vsavolai          #+#    #+#             */
/*   Updated: 2023/11/10 09:20:23 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*r;
	size_t	i;
	size_t	j;

	r = (char *)haystack;
	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return (r);
	while (0 < len && haystack[i] != '\0')
	{
		while (needle[j] == haystack[i] && len > 0)
		{
			i++;
			j++;
			len--;
			if (needle[j] == '\0')
				return (r);
		}
		i = i - j + 1;
		len += j - 1;
		j = 0;
		r++;
	}
	return (NULL);
}
