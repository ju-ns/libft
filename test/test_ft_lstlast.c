/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:11:24 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 10:11:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TEST(desc, cond) do { \
	if (!(cond)) { \
		printf("Test failed: %s\n", desc); \
		fail = 1; \
	} \
} while (0)

int main(void)
{
	int fail = 0;

	// TESTE 1: lista vazia
	t_list *lst1 = NULL;
	TEST("ft_lstlast deve retornar NULL para lista vazia", ft_lstlast(lst1) == NULL);

	// TESTE 2: lista com 1 nó
	t_list *node = ft_lstnew("único");
	TEST("ft_lstlast deve retornar o próprio nó se só há um", ft_lstlast(node) == node);
	free(node);

	// TESTE 3: lista com vários nós
	t_list *n1 = ft_lstnew("primeiro");
	t_list *n2 = ft_lstnew("meio");
	t_list *n3 = ft_lstnew("último");

	n1->next = n2;
	n2->next = n3;

	TEST("ft_lstlast deve retornar o último nó", ft_lstlast(n1) == n3);

	free(n1);
	free(n2);
	free(n3);

	return fail;
}
