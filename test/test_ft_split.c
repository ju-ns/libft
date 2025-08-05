/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:52:52 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 15:52:52 by marvin           ###   ########.fr       */
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

    return (fail);

}