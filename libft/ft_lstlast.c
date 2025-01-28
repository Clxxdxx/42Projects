/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:17:00 by clalopez          #+#    #+#             */
/*   Updated: 2025/01/28 10:13:21 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	count;

	if (!lst)
		return (NULL);
	count = 0;
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
		count++;
	}
	return (lst);
}
