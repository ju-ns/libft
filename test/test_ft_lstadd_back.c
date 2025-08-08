/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:44:38 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/08 11:58:13 by jnogueir         ###   ########.fr       */
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
	
	// TEST 5: Novo nó é NULL
	t_list *list2 = NULL;
	ft_lstadd_back(&list2, NULL);
	TEST("Lista deve permanecer NULL se novo nó é NULL", list2 == NULL);

	// TEST 6: Lista com múltiplos elementos, adiciona no fim
	t_list *list3 = ft_lstnew("a");
	t_list *n2 = ft_lstnew("b");
	t_list *n3 = ft_lstnew("c");
	list3->next = n2;
	n2->next = n3;

	t_list *n4 = ft_lstnew("d");
	ft_lstadd_back(&list3, n4);

	TEST("n3->next deve apontar para n4", n3->next == n4);
	TEST("n4->next deve ser NULL", n4->next == NULL);

	// TEST 7: Nó já encadeado
	t_list *list4 = ft_lstnew("x");
	t_list *list5 = ft_lstnew("y");
	list4->next = list5;

	t_list *extra = ft_lstnew("z");
	extra->next = ft_lstnew("w");

	ft_lstadd_back(&list4, extra);
	TEST("list5->next deve apontar para extra", list5->next == extra);
	TEST("extra->next->content deve ser 'w'", strcmp(extra->next->content, "w") == 0);

	// TEST 8: Inserções consecutivas
	t_list *list6 = ft_lstnew("1");
	ft_lstadd_back(&list6, ft_lstnew("2"));
	ft_lstadd_back(&list6, ft_lstnew("3"));
	ft_lstadd_back(&list6, ft_lstnew("4"));

	t_list *tmp = list6;
	int count = 0;
	while (tmp) { count++; tmp = tmp->next; }
	TEST("Lista deve ter 4 elementos", count == 4);


	// Limpeza
	free(node1);
	free(node2);
	free(node3);
	free(list5);
	free(extra->next);
	free(extra);
	free(list6->next->next->next);
	free(list6->next->next);
	free(list6->next);
	free(list6);

	return (fail);
}