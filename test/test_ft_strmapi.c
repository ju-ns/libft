/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:16:18 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 18:16:18 by marvin           ###   ########.fr       */
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
} while(0)

#define ASSERT_STR_EQ(a, b, desc) do { \
	if (strcmp((a), (b)) != 0) { \
		printf("Test failed: %s\nExpected: \"%s\", Got: \"%s\"\n", desc, b, a); \
		fail = 1; \
	} \
} while(0)

static char add_index(unsigned int i, char c)
{
	return (c + i);
}

static char to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int main(void)
{
	int fail = 0;

    // TESTE 1: Soma o índice ao caractere original
	// Ex: 'a'+0 = 'a', 'b'+1 = 'c', 'c'+2 = 'e', 'd'+3 = 'g'
	char *res1 = ft_strmapi("abcd", add_index);
	ASSERT_STR_EQ(res1, "aceg", "ft_strmapi com função que soma índice");
	free(res1);

	// TESTE 2: Converte todos os caracteres para maiúsculo, ignorando o índice
	char *res2 = ft_strmapi("AbCd", to_upper);
	ASSERT_STR_EQ(res2, "ABCD", "ft_strmapi com função que converte para maiúsculo");
	free(res2);

	// TESTE 3: String vazia deve retornar string vazia
	char *res3 = ft_strmapi("", add_index);
	ASSERT_STR_EQ(res3, "", "ft_strmapi com string vazia");
	free(res3);

	// TESTE 4: Entrada nula deve retornar NULL
	char *res4 = ft_strmapi(NULL, add_index);
	TEST("ft_strmapi com entrada NULL retorna NULL", res4 == NULL);

	return (fail);
}
