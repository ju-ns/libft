/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 00:37:27 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 00:37:27 by marvin           ###   ########.fr       */
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

// Função de deleção que seta uma flag
int del_called = 0;
void mock_del(void *content) {
	del_called = 1;
	free(content); // libera o conteúdo real
}

int	main(void)
{
	int fail = 0;

	// TEST 1: lstdelone chama del e libera o nó
	char *data = strdup("to be deleted");
	t_list *node = ft_lstnew(data);

	ft_lstdelone(node, mock_del);

	TEST("função del deve ser chamada", del_called == 1);

	// Se você quiser forçar um teste de vazamento, pode rodar com valgrind

	return (fail);
}
