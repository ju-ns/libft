/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:10:32 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 10:10:32 by marvin           ###   ########.fr       */
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
	t_list *list1 = NULL;
	TEST("ft_lstsize deve retornar 0 para lista vazia", ft_lstsize(list1) == 0);

	// TESTE 2: lista com 1 elemento
	t_list *node1 = ft_lstnew("a");
	TEST("ft_lstsize deve retornar 1 para lista com 1 nó", ft_lstsize(node1) == 1);
	free(node1);

	// TESTE 3: lista com 3 elementos
	t_list *n1 = ft_lstnew("x");
	t_list *n2 = ft_lstnew("y");
	t_list *n3 = ft_lstnew("z");
	n1->next = n2;
	n2->next = n3;

	TEST("ft_lstsize deve retornar 3 para lista com 3 nós", ft_lstsize(n1) == 3);

	free(n1);
	free(n2);
	free(n3);

	return fail;
}
