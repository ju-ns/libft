/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:52:52 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 13:34:57 by jnogueir         ###   ########.fr       */
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

#define ASSERT_STR_EQ(actual, expected, description) do { \
	if (strcmp((actual), (expected)) != 0) { \
		printf("Test failed: %s\nExpected: \"%s\", Got: \"%s\"\n", description, expected, actual); \
		fail = 1; \
	} \
} while (0)

static void free_split(char **arr) {
	int i = 0;
	if (!arr) return;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int main() {
	int fail = 0;

	// TEST 1: string comum separada por espaço
	char **res1 = ft_split("ola mundo legal", ' ');
	ASSERT_STR_EQ(res1[0], "ola", "split[0] deve ser 'ola'");
	ASSERT_STR_EQ(res1[1], "mundo", "split[1] deve ser 'mundo'");
	ASSERT_STR_EQ(res1[2], "legal", "split[2] deve ser 'legal'");
	TEST("split[3] deve ser NULL", res1[3] == NULL);
	free_split(res1);

    // TEST 2: múltiplos separadores consecutivos
	char **res2 = ft_split("a,,b,,,c", ',');
	ASSERT_STR_EQ(res2[0], "a", "split[0] deve ser 'a'");
	ASSERT_STR_EQ(res2[1], "b", "split[1] deve ser 'b'");
	ASSERT_STR_EQ(res2[2], "c", "split[2] deve ser 'c'");
	TEST("split[3] deve ser NULL", res2[3] == NULL);
	free_split(res2);

	// TEST 3: separador no começo e fim
	char **res3 = ft_split(",a,b,", ',');
	ASSERT_STR_EQ(res3[0], "a", "split[0] deve ser 'a'");
	ASSERT_STR_EQ(res3[1], "b", "split[1] deve ser 'b'");
	TEST("split[2] deve ser NULL", res3[2] == NULL);
	free_split(res3);

	// TEST 4: string com apenas separadores
	char **res4 = ft_split(",,,", ',');
	TEST("split deve conter apenas NULL", res4[0] == NULL);
	free_split(res4);

	// TEST 5: string vazia
	char **res5 = ft_split("", ',');
	TEST("split de string vazia deve conter apenas NULL", res5[0] == NULL);
	free_split(res5);

	// TESTE 6: sem separadores (string inteira como único token)
	char **res6 = ft_split("unicotoken", ',');
	ASSERT_STR_EQ(res6[0], "unicotoken", "split[0] deve ser 'unicotoken'");
	TEST("split[1] deve ser NULL", res6[1] == NULL);
	free_split(res6);

	// TESTE 7: string com um único token
	char **res7 = ft_split("token", ' ');
	ASSERT_STR_EQ(res7[0], "token", "split[0] deve ser 'token'");
	TEST("split[1] deve ser NULL", res7[1] == NULL);
	free_split(res7);

	// TESTE 8: separador '\0'
	char **res8 = ft_split("abc", '\0');
	ASSERT_STR_EQ(res8[0], "abc", "split[0] deve ser 'abc'");
	TEST("split[1] deve ser NULL", res8[1] == NULL);
	free_split(res8);

	// TESTE 9: separador diferente do presente (espaços ignorados)
	char **res9 = ft_split(" a b ", ',');
	ASSERT_STR_EQ(res9[0], " a b ", "split deve conter a string inteira");
	TEST("split[1] deve ser NULL", res9[1] == NULL);
	free_split(res9);

	// TESTE 10: separador sendo caractere especial (\t)
	char **res10 = ft_split("ab\tcd\tef", '\t');
	ASSERT_STR_EQ(res10[0], "ab", "split[0] deve ser 'ab'");
	ASSERT_STR_EQ(res10[1], "cd", "split[1] deve ser 'cd'");
	ASSERT_STR_EQ(res10[2], "ef", "split[2] deve ser 'ef'");
	TEST("split[3] deve ser NULL", res10[3] == NULL);
	free_split(res10);

	// TESTE 11: NULL como entrada (comportamento opcional)
	char **res11 = ft_split(NULL, ' ');
	TEST("ft_split(NULL) deve retornar NULL", res11 == NULL);
	free_split(res11);

    return (fail);

}