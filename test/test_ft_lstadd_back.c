/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:36:57 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 00:36:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEST(desc, cond) do { \
	if (!(cond)) { \
		printf("Test failed: %s\n", desc); \
		fail = 1; \
	} \
} while (0)

int	main(void)
{
	int fail = 0;

	// TEST 1: Adiciona em lista vazia
	t_list *list1 = NULL;
	t_list *node1 = ft_lstnew("first");
	ft_lstadd_back(&list1, node1);

	TEST("ft_lstadd_back deve atualizar head quando lista está vazia", list1 == node1);
	TEST("ft_lstadd_back deve manter conteúdo correto", strcmp(list1->content, "first") == 0);
	TEST("next do único nó deve ser NULL", list1->next == NULL);

	// TEST 2: Adiciona no final de uma lista com um elemento
	t_list *node2 = ft_lstnew("second");
	ft_lstadd_back(&list1, node2);

	TEST("node1->next deve apontar para node2", node1->next == node2);
	TEST("node2->next deve ser NULL", node2->next == NULL);

	// TEST 3: Adiciona mais um nó no fim da lista
	t_list *node3 = ft_lstnew("third");
	ft_lstadd_back(&list1, node3);

	TEST("node2->next deve apontar para node3", node2->next == node3);
	TEST("node3->next deve ser NULL", node3->next == NULL);

	// TEST 4: Verifica encadeamento completo
	TEST("head da lista ainda é node1", list1 == node1);
	TEST("node1->next->content deve ser 'second'", strcmp(node1->next->content, "second") == 0);
	TEST("node1->next->next->content deve ser 'third'", strcmp(node1->next->next->content, "third") == 0);

	// Limpeza
	free(node1);
	free(node2);
	free(node3);

	return (fail);
}
