/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:35:09 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/08 13:37:02 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	next_node = *lst;
	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		next_node = (*lst)->next;
		if (del)
			del((*lst)->content);
		else
			free((*lst)->content);
		free(*lst);
		*lst = next_node;
	}
	*lst = NULL;
}
//outra versão reaproveitando a função lstdelone
// void	ft_lstclear(t_list **lst, void(*del)(void *))
// {
// 	t_list	*temp;

// 	if (!lst || !*lst)
// 		return ;
// 	while (*lst)
// 	{
// 		temp = (*lst)->next;
// 		ft_lstdelone(*lst, del);
// 		*lst = temp;
// 	}
// }