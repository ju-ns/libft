/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:38:19 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 00:38:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST(desc, cond) do { \
	if (!(cond)) { \
		printf("Test failed: %s\n", desc); \
		fail = 1; \
	} \
} while (0)

int del_count = 0;
void mock_del(void *content)
{
	del_count++;
	free(content);  // libera o conteúdo real
}

int main(void)
{
	int fail = 0;

	// Cria uma lista de 3 nós
	t_list *lst = ft_lstnew(strdup("node1"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("node2")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("node3")));

	ft_lstclear(&lst, mock_del);

	TEST("ft_lstclear deve chamar del 3 vezes", del_count == 3);
	TEST("após ft_lstclear, lst deve ser NULL", lst == NULL);

	return fail;
}
