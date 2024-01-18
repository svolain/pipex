/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:29:36 by vsavolai          #+#    #+#             */
/*   Updated: 2023/11/10 09:20:35 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;
	char	cc;

	cc = c;
	found = NULL;
	while (*s)
	{
		if (*s == cc)
			found = (char *)s;
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (found);
}
