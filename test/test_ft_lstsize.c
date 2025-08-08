/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:47:24 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/08 12:20:39 by jnogueir         ###   ########.fr       */
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

	// TESTE 4: lista com 2 nós, verifica ponteiro next
	t_list *a = ft_lstnew("a");
	t_list *b = ft_lstnew("b");
	a->next = b;
	TEST("ft_lstsize retorna 2 para lista com 2 nós", ft_lstsize(a) == 2);
	free(a);
	free(b);

	// TESTE 5: lista com nó cujo next é NULL em meio da lista (encadeamento interrompido)
	t_list *x = ft_lstnew("x");
	t_list *y = ft_lstnew("y");
	x->next = NULL;  // lista interrompida após x
	y->next = NULL;
	TEST("ft_lstsize retorna 1 se next do primeiro nó é NULL", ft_lstsize(x) == 1);
	free(x);
	free(y);

	// TESTE 6: lista longa com 10 nós
	t_list *head = ft_lstnew(strdup("0"));
	t_list *curr = head;
	for (int i = 1; i < 10; i++) {
		curr->next = ft_lstnew(strdup("node"));
		curr = curr->next;
	}
	TEST("ft_lstsize retorna 10 para lista longa", ft_lstsize(head) == 10);

	// limpeza lista longa
	curr = head;
	while (curr)
	{
		t_list *tmp = curr->next;
		free(curr->content);
		free(curr);
		curr = tmp;
	}

	// TESTE 7: lista com nó cujo conteúdo é NULL
	t_list *null_content_node = ft_lstnew(NULL);
	TEST("ft_lstsize retorna 1 para nó com conteúdo NULL", ft_lstsize(null_content_node) == 1);
	free(null_content_node);

	return fail;
}