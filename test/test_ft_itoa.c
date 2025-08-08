/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:30:00 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 13:14:23 by jnogueir         ###   ########.fr       */
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

#define ASSERT_STR_EQ(actual, expected, desc) do { \
	if (strcmp((actual), (expected)) != 0) { \
		printf("Test failed: %s\nExpected: \"%s\", Got: \"%s\"\n", desc, expected, actual); \
		fail = 1; \
	} \
} while (0)

int main(void)
{
	int fail = 0;
	char *res;

	// TESTE 1: número positivo simples
	res = ft_itoa(123);
	ASSERT_STR_EQ(res, "123", "ft_itoa com número positivo");
	free(res);

	// TESTE 2: número negativo simples
	res = ft_itoa(-456);
	ASSERT_STR_EQ(res, "-456", "ft_itoa com número negativo");
	free(res);

	// TESTE 3: zero
	res = ft_itoa(0);
	ASSERT_STR_EQ(res, "0", "ft_itoa com zero");
	free(res);

	// TESTE 4: INT_MIN (-2147483648)
	res = ft_itoa(-2147483648);
	ASSERT_STR_EQ(res, "-2147483648", "ft_itoa com INT_MIN");
	free(res);

	// TESTE 5: INT_MAX (2147483647)
	res = ft_itoa(2147483647);
	ASSERT_STR_EQ(res, "2147483647", "ft_itoa com INT_MAX");
	free(res);

	// TESTE 6: número de um dígito
	res = ft_itoa(7);
	ASSERT_STR_EQ(res, "7", "ft_itoa com número de um dígito");
	free(res);

	// TESTE 7: número negativo de um dígito
	res = ft_itoa(-7);
	TEST("ft_itoa retornou NULL para número negativo de um dígito", res != NULL);
	ASSERT_STR_EQ(res, "-7", "ft_itoa com número negativo de um dígito");
	free(res);

	// TESTE 8: números com zeros à esquerda no resultado
	res = ft_itoa(10);
	TEST("ft_itoa retornou NULL para 10", res != NULL);
	ASSERT_STR_EQ(res, "10", "ft_itoa com número 10");
	free(res);

	res = ft_itoa(100);
	TEST("ft_itoa retornou NULL para 100", res != NULL);
	ASSERT_STR_EQ(res, "100", "ft_itoa com número 100");
	free(res);

	res = ft_itoa(1000);
	TEST("ft_itoa retornou NULL para 1000", res != NULL);
	ASSERT_STR_EQ(res, "1000", "ft_itoa com número 1000");
	free(res);

	// TESTE 9: número negativo próximo de zero
	res = ft_itoa(-1);
	TEST("ft_itoa retornou NULL para -1", res != NULL);
	ASSERT_STR_EQ(res, "-1", "ft_itoa com número -1");
	free(res);

	// TESTE 10: número grande positivo
	res = ft_itoa(123456789);
	TEST("ft_itoa retornou NULL para número grande positivo", res != NULL);
	ASSERT_STR_EQ(res, "123456789", "ft_itoa com número grande positivo");
	free(res);

	// TESTE 11: número grande negativo
	res = ft_itoa(-123456789);
	TEST("ft_itoa retornou NULL para número grande negativo", res != NULL);
	ASSERT_STR_EQ(res, "-123456789", "ft_itoa com número grande negativo");
	free(res);

	return (fail);
}
