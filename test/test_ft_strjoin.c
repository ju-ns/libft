/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 00:46:05 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 14:31:22 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TEST(description, condition) do { \
	if (!(condition)) { \
		printf("Test failed: %s\n", description); \
		fail = 1; \
	} \
} while (0)

#define ASSERT_STR_EQ(a, b, description) do { \
	if (strcmp((a), (b)) != 0) { \
		printf("Test failed: %s\nExpected: \"%s\", Got: \"%s\"\n", description, b, a); \
		fail = 1; \
	} \
} while (0)

int main() {
	int fail = 0;

	// TEST 1: concatenação simples
	char *res1 = ft_strjoin("Hello, ", "world!");
	ASSERT_STR_EQ(res1, "Hello, world!", "ft_strjoin should concatenate two normal strings");
	free(res1);

    // TEST 2: strings vazias
	char *res2 = ft_strjoin("", "");
	ASSERT_STR_EQ(res2, "", "ft_strjoin with two empty strings should return empty string");
	free(res2);

	// TEST 3: uma string vazia (esquerda)
	char *res3 = ft_strjoin("", "right");
	ASSERT_STR_EQ(res3, "right", "ft_strjoin with empty left string should return right string");
	free(res3);

	// TEST 4: uma string vazia (direita)
	char *res4 = ft_strjoin("left", "");
	ASSERT_STR_EQ(res4, "left", "ft_strjoin with empty right string should return left string");
	free(res4);

	// TEST 5: strings com espaço
	char *res5 = ft_strjoin("foo ", "bar");
	ASSERT_STR_EQ(res5, "foo bar", "ft_strjoin should preserve spaces during concatenation");
	free(res5);

	// TEST 6: caracteres especiais
	char *res6 = ft_strjoin("42_", "!@#$%");
	ASSERT_STR_EQ(res6, "42_!@#$%", "ft_strjoin should handle special characters");
	free(res6);

	// TEST 7: strings com quebra de linha
	char *res7 = ft_strjoin("line1\n", "line2");
	ASSERT_STR_EQ(res7, "line1\nline2", "ft_strjoin should handle newlines");
	free(res7);
	
	// TEST 8: concatenação de strings muito longas
	char long1[1001], long2[1001];
	memset(long1, 'a', 1000);
	memset(long2, 'b', 1000);
	long1[1000] = '\0';
	long2[1000] = '\0';
	char *res8 = ft_strjoin(long1, long2);
	TEST("ft_strjoin should handle very long strings", res8 != NULL && strlen(res8) == 2000);
	free(res8);

	// TEST 9: concatenação de strings iguais
	char *res9 = ft_strjoin("same", "same");
	ASSERT_STR_EQ(res9, "samesame", "ft_strjoin with identical strings");
	free(res9);


    return (fail);
}