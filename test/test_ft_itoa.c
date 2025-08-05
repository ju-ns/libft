/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:30:00 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 22:30:00 by marvin           ###   ########.fr       */
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

	return (fail);
}
