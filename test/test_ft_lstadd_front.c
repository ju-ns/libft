/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:44:59 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/08 13:37:40 by jnogueir         ###   ########.fr       */
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
	ft_lstadd_front(&list1, node1);

	TEST("ft_lstadd_front deve atualizar head quando lista está vazia", list1 == node1);
	TEST("ft_lstadd_front deve manter conteúdo correto", strcmp(list1->content, "first") == 0);

	// TEST 2: Adiciona novo nó na frente de uma lista existente
	t_list *node2 = ft_lstnew("second");
	ft_lstadd_front(&list1, node2);

	TEST("ft_lstadd_front deve atualizar head corretamente", list1 == node2);
	TEST("novo head deve apontar para o antigo head", list1->next == node1);
	TEST("conteúdo do novo head", strcmp(list1->content, "second") == 0);
	TEST("conteúdo do próximo nó", strcmp(list1->next->content, "first") == 0);

	// TEST 3: Adicionar múltiplos nós
	t_list *node3 = ft_lstnew("third");
	ft_lstadd_front(&list1, node3);

	TEST("head agora deve ser o node3", list1 == node3);
	TEST("node3->next deve ser node2", list1->next == node2);
	TEST("node2->next deve ser node1", node2->next == node1);

	// TEST 4: Novo nó é NULL
	t_list *list2 = NULL;
	ft_lstadd_front(&list2, NULL);
	TEST("Lista deve permanecer NULL se novo nó é NULL", list2 == NULL);
	
	// TEST 5: Inserções consecutivas
	t_list *list3 = NULL;
	ft_lstadd_front(&list3, ft_lstnew("1"));
	ft_lstadd_front(&list3, ft_lstnew("2"));
	ft_lstadd_front(&list3, ft_lstnew("3"));

	t_list *tmp = list3;
	int count = 0;
	while (tmp) { count++; tmp = tmp->next; }
	TEST("Lista deve ter 3 elementos", count == 3);
	TEST("Ordem deve ser 3 -> 2 -> 1",
		strcmp(list3->content, "3") == 0 &&
		strcmp(list3->next->content, "2") == 0 &&
		strcmp(list3->next->next->content, "1") == 0);

	// TEST 6: Lista com vários elementos, adiciona na frente
	t_list *list4 = ft_lstnew("a");
	list4->next = ft_lstnew("b");
	list4->next->next = ft_lstnew("c");

	t_list *n_front = ft_lstnew("z");
	ft_lstadd_front(&list4, n_front);

	TEST("Novo head deve ser 'z'", strcmp(list4->content, "z") == 0);
	TEST("z->next deve apontar para 'a'", strcmp(list4->next->content, "a") == 0);


	// Limpeza
	free(node1);
	free(node2);
	free(node3);
	free(list3->next->next);
	free(list3->next);
	free(list3);
	free(list4->next->next);
	free(list4->next);
	free(list4);

	return (fail);
}