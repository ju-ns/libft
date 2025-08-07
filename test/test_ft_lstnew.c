/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:09:01 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 10:09:01 by marvin           ###   ########.fr       */
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

	// TESTE 1: conteúdo de string
	char *str = strdup("42sp");
	t_list *node1 = ft_lstnew(str);

	TEST("node1 não deve ser NULL", node1 != NULL);
	TEST("node1->content deve apontar para '42sp'", strcmp((char *)node1->content, "42sp") == 0);
	TEST("node1->next deve ser NULL", node1->next == NULL);

	free(node1->content);
	free(node1);

	// TESTE 2: conteúdo numérico (simples cast de ponteiro)
	int value = 42;
	t_list *node2 = ft_lstnew(&value);
	TEST("node2->content deve apontar para 42", *((int *)node2->content) == 42);
	TEST("node2->next deve ser NULL", node2->next == NULL);
	free(node2); // não precisa liberar value

	// TESTE 3: conteúdo NULL
	t_list *node3 = ft_lstnew(NULL);
	TEST("node3 deve aceitar content NULL", node3->content == NULL);
	TEST("node3->next deve ser NULL", node3->next == NULL);
	free(node3);

	return fail;
}
