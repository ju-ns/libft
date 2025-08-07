/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:35:46 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 00:35:46 by marvin           ###   ########.fr       */
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

	// Limpeza
	free(node1);
	free(node2);
	free(node3);

	return (fail);
}
