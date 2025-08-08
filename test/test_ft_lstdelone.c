/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:45:34 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/08 12:50:52 by jnogueir         ###   ########.fr       */
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

// Flags para saber se del foi chamado
int del_called = 0;
int del_called_no_free = 0;

// Função de deleção que libera conteúdo e seta flag
void mock_del(void *content) {
	del_called = 1;
	free(content);
}

// Função de deleção que só seta flag, não libera conteúdo
void mock_del_no_free(void *content) {
	(void)content;
	del_called_no_free = 1;
}

int main(void)
{
	int fail = 0;

	// TEST 1: Nó com conteúdo alocado
	del_called = 0;
	t_list *node1 = ft_lstnew(strdup("to be deleted"));
	ft_lstdelone(node1, mock_del);
	TEST("del deve ser chamado 1 vez", del_called == 1);

	// TEST 2: Nó com content NULL
	del_called = 0;
	t_list *node2 = ft_lstnew(NULL);
	ft_lstdelone(node2, mock_del);
	TEST("del chamado mesmo com content NULL", del_called == 1);

	// TEST 3: Nó isolado (não há next para liberar)
	del_called = 0;
	t_list *node3 = ft_lstnew(strdup("isolated"));
	node3->next = NULL;
	ft_lstdelone(node3, mock_del);
	TEST("del chamado 1 vez em nó isolado", del_called == 1);

	// TEST 4: Função del é NULL (não deve crashar e nó deve ser liberado)
	t_list *node4 = ft_lstnew(strdup("no del"));
	ft_lstdelone(node4, NULL);
	TEST("sem del, nó deve ser liberado sem crash", 1); // só verifica que não travou

	// TEST 5: Conteúdo não alocado dinamicamente — del não libera conteúdo
	int x = 42;
	del_called_no_free = 0;
	t_list *node5 = ft_lstnew(&x);
	ft_lstdelone(node5, mock_del_no_free);
	TEST("del chamado mesmo com conteúdo estático", del_called_no_free == 1);

	return (fail);
}
