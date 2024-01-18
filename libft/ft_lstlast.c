/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavolai <vsavolai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:56:18 by vsavolai          #+#    #+#             */
/*   Updated: 2023/11/09 14:21:36 by vsavolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	int		lsize;
	t_list	*temp;

	i = 0;
	temp = lst;
	lsize = ft_lstsize(lst);
	while (i < lsize - 1)
	{
		i++;
		temp = temp->next;
	}
	return (temp);
}
