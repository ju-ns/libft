/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:46:52 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/08 13:38:34 by jnogueir         ###   ########.fr       */
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


typedef struct {
	int a;
	char b;
} t_sample;

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

	// TESTE 4: conteúdo grande (array)
	char *big_str = malloc(1000);
	memset(big_str, 'A', 999);
	big_str[999] = '\0';
	t_list *node4 = ft_lstnew(big_str);
	TEST("node4->content deve apontar para big_str", node4->content == big_str);
	TEST("node4->next deve ser NULL", node4->next == NULL);
	free(big_str);
	free(node4);

	// TESTE 5: conteúdo pointer para struct
	t_sample sample = {123, 'Z'};
	t_list *node5 = ft_lstnew(&sample);
	TEST("node5->content deve apontar para struct", node5->content == &sample);
	TEST("node5->next deve ser NULL", node5->next == NULL);
	free(node5);
	
	// TESTE 6: conteúdo pointer para NULL após alocação manual
	char *dynamic_str = strdup("dynamic");
	t_list *node6 = ft_lstnew(dynamic_str);
	TEST("node6->content deve apontar para 'dynamic'", strcmp((char *)node6->content, "dynamic") == 0);
	TEST("node6->next deve ser NULL", node6->next == NULL);
	free(dynamic_str);
	free(node6);


	return fail;
}