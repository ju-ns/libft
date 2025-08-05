/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:00:00 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 22:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

#define TEST(desc, cond) do { \
	if (!(cond)) { \
		printf("Test failed: %s\n", desc); \
		fail = 1; \
	} \
} while (0)

#define ASSERT_STR_EQ(actual, expected, desc) do { \
	if (strcmp((actual), (expected)) != 0) { \
		printf("Test failed: %s\nExpected: \"%s\", Got: \"%s\"\n", desc, expected, actual); \
		fail = 1; \
	} \
} while (0)

// Função que transforma a string para maiúsculo (in-place)
static void to_upper_iteri(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

// Função que soma o índice ao caractere (in-place)
static void add_index_iteri(unsigned int i, char *c)
{
	*c += i;
}

int main(void)
{
	int fail = 0;

	// TESTE 1: transforma string em maiúsculo
	char str1[] = "Libft";
	ft_striteri(str1, to_upper_iteri);
	ASSERT_STR_EQ(str1, "LIBFT", "ft_striteri transforma em maiúsculo");

	// TESTE 2: soma índice ao caractere
	char str2[] = "abcd";
	ft_striteri(str2, add_index_iteri); // 'a'+0, 'b'+1, 'c'+2, 'd'+3 → aceg
	ASSERT_STR_EQ(str2, "aceg", "ft_striteri soma índice ao caractere");

	// TESTE 3: string vazia (não deve falhar ou modificar nada)
	char str3[] = "";
	ft_striteri(str3, to_upper_iteri);
	ASSERT_STR_EQ(str3, "", "ft_striteri com string vazia");

	// TESTE 4: string NULL (não deve causar crash)
	ft_striteri(NULL, to_upper_iteri);
	TEST("ft_striteri com string NULL não deve crashar", 1);

	// TESTE 5: função NULL (não deve causar crash)
	char str5[] = "abc";
	ft_striteri(str5, NULL);
	TEST("ft_striteri com função NULL não deve crashar", 1);

	return (fail);
}
