/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:08:13 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 01:08:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TEST(description, condition) do { \
	if (!(condition)) { \printf("Test failed: %s\n", description); \
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

	// TEST 1: espaços no início e fim
	char *res1 = ft_strtrim("   42sp   ", " ");
	ASSERT_STR_EQ(res1, "42sp", "ft_strtrim deve remover espaços nas pontas");
	free(res1);

	// TEST 2: múltiplos caracteres no set
	char *res2 = ft_strtrim("!!@hello@!!", "!@");
	ASSERT_STR_EQ(res2, "hello", "ft_strtrim deve remover vários caracteres do início/fim");
	free(res2);

	// TEST 3: string sem caracteres do set
	char *res3 = ft_strtrim("abc", " ");
	ASSERT_STR_EQ(res3, "abc", "ft_strtrim não deve alterar se não houver caracteres do set");
	free(res3);

	// TEST 4: string inteira composta por caracteres do set
	char *res4 = ft_strtrim("$$$", "$");
	ASSERT_STR_EQ(res4, "", "ft_strtrim deve retornar string vazia se todos forem do set");
	free(res4);

	// TEST 5: set vazio
	char *res5 = ft_strtrim("abc", "");
	ASSERT_STR_EQ(res5, "abc", "ft_strtrim com set vazio não deve cortar nada");
	free(res5);

	// TEST 6: string vazia
	char *res6 = ft_strtrim("", " ");
	ASSERT_STR_EQ(res6, "", "ft_strtrim com string vazia deve retornar string vazia");
	free(res6);

	// TEST 7: caracteres diferentes no início e fim
	char *res7 = ft_strtrim("*~hello~*", "*~");
	ASSERT_STR_EQ(res7, "hello", "ft_strtrim deve remover qualquer caractere do set nas pontas");
	free(res7);

	return fail;
}

