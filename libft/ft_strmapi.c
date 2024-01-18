/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:47:57 by vsavolai          #+#    #+#             */
/*   Updated: 2023/11/09 15:19:48 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	rlen;
	size_t	i;
	char	*r;

	i = 0;
	if (!s || !f)
		return (0);
	rlen = ft_strlen(s);
	r = malloc(sizeof(char) * (rlen + 1));
	if (!r)
		return (0);
	while (i < rlen)
	{
		r[i] = f(i, s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
