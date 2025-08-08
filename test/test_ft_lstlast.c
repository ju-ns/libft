/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:46:15 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/08 12:13:58 by jnogueir         ###   ########.fr       */
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

	// TESTE 4: lista com 2 nós (testa ponteiro next direto)
	t_list *a = ft_lstnew("a");
	t_list *b = ft_lstnew("b");
	a->next = b;

	TEST("ft_lstlast retorna nó final em lista com 2 nós", ft_lstlast(a) == b);

	free(a);
	free(b);

	// TESTE 5: lista encadeada manualmente com NULL intermediário (inválido)
	t_list *x = ft_lstnew("x");
	t_list *y = ft_lstnew("y");
	x->next = NULL;  // quebra encadeamento, nó y "solto"

	TEST("ft_lstlast retorna x quando next é NULL no primeiro nó", ft_lstlast(x) == x);

	free(x);
	free(y);

	// TESTE 6: lista longa (10 nós) para testar performance básica
	t_list *head = ft_lstnew(strdup("0"));
	t_list *curr = head;
	for (int i = 1; i < 10; i++) {
		curr->next = ft_lstnew(strdup("node"));
		curr = curr->next;
	}
	TEST("ft_lstlast retorna último nó em lista longa", ft_lstlast(head) == curr);

	// limpeza
	curr = head;
	while (curr)
	{
		t_list *tmp = curr->next;
		free(curr->content);
		free(curr);
		curr = tmp;
	}

	// TESTE 7: nó cujo conteúdo é NULL
	t_list *null_content_node = ft_lstnew(NULL);
	TEST("ft_lstlast retorna nó com content NULL", ft_lstlast(null_content_node) == null_content_node);
	free(null_content_node);


	return fail;
}