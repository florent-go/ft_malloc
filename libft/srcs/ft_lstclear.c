/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:37:29 by fgomez            #+#    #+#             */
/*   Updated: 2021/01/26 12:43:18 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *entry;

	entry = *lst;
	while (entry)
	{
		tmp = entry->next;
		if (del)
		{
			del(entry->content);
		}
		free(entry);
		entry = tmp;
	}
	*lst = NULL;
}
