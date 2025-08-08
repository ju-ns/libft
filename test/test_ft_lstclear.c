/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:45:19 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/08 12:06:36 by jnogueir         ###   ########.fr       */
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

	// TEST 1: Cria uma lista de 3 nós
	t_list *lst = ft_lstnew(strdup("node1"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("node2")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("node3")));

	ft_lstclear(&lst, mock_del);

	TEST("ft_lstclear deve chamar del 3 vezes", del_count == 3);
	TEST("após ft_lstclear, lst deve ser NULL", lst == NULL);

	// TEST 2: Lista NULL
	t_list *null_list = NULL;
	del_count = 0;
	ft_lstclear(&null_list, mock_del);
	TEST("Lista NULL não deve chamar del", del_count == 0);
	TEST("Lista NULL permanece NULL", null_list == NULL);

	// TEST 3: Lista já vazia (ponteiro válido mas NULL)
	t_list *empty_list = NULL;
	del_count = 0;
	ft_lstclear(&empty_list, mock_del);
	TEST("Lista vazia não chama del", del_count == 0);
	TEST("Lista vazia permanece NULL", empty_list == NULL);
	
	// TEST 4: Lista com 1 nó
	t_list *single = ft_lstnew(strdup("only"));
	del_count = 0;
	ft_lstclear(&single, mock_del);
	TEST("del deve ser chamado 1 vez", del_count == 1);
	TEST("Lista deve ser NULL", single == NULL);

	// TEST 5: Nó com content NULL
	t_list *null_content_list = ft_lstnew(NULL);
	del_count = 0;
	ft_lstclear(&null_content_list, mock_del);
	TEST("del deve ser chamado 1 vez mesmo se content for NULL", del_count == 1);
	TEST("Lista deve ser NULL", null_content_list == NULL);

	// TEST 6: del é NULL (comportamento indefinido pela norma)
	t_list *lst2 = ft_lstnew(strdup("one"));
	ft_lstadd_back(&lst2, ft_lstnew(strdup("two")));
	ft_lstadd_back(&lst2, ft_lstnew(strdup("three")));

	// pode quebrar se n tratar del null
	ft_lstclear(&lst2, NULL);
	TEST("Lista deve ser NULL após clear mesmo com del NULL", lst2 == NULL);

	// TEST 7: Conteúdos mistos (malloc int, NULL, string)
	t_list *mixed = ft_lstnew(malloc(sizeof(int)));
	ft_lstadd_back(&mixed, ft_lstnew(NULL));
	ft_lstadd_back(&mixed, ft_lstnew(strdup("string")));
	del_count = 0;
	ft_lstclear(&mixed, mock_del);
	TEST("del chamado para todos os nós", del_count == 3);
	TEST("lista deve ser NULL", mixed == NULL);

	return fail;
}