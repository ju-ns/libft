/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:04:26 by jnogueir          #+#    #+#             */
/*   Updated: 2025/07/25 13:18:44 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include <limits.h>

#define TEST(passed, expected, input) do { \
	int result = (passed); \
	if(result != (expected)) { \
		printf("Test failed ft_isascii: expected %d, got %d for input '%c'\n", (expected), result, (input)); \
		fail = 1; \
	} \
} while (0)

int main (){
	int fail = 0;

	TEST(ft_isascii(0), 1, 0);
	TEST(ft_isascii(127), 1, 127);

	TEST(ft_isascii(65), 1, 65);
	TEST(ft_isascii(32), 1, 32);
	TEST(ft_isascii(10), 1, 10);

	TEST(ft_isascii(-1), 0, -1);
	TEST(ft_isascii(-128), 0, -128);

	TEST(ft_isascii(128), 0, 128);
	TEST(ft_isascii(255), 0, 255);
	TEST(ft_isascii(300), 0, 300);

	// Testa toda a faixa ASCII 0-127
	for (int i = 0; i <= 127; i++) {
		TEST(ft_isascii(i), 1, i);
	}

	// Testes perto das bordas
	TEST(ft_isascii(-129), 0, -129);
	TEST(ft_isascii(129), 0, 129);

	// Testes extremos com INT_MIN e INT_MAX
	TEST(ft_isascii(INT_MIN), 0, INT_MIN);
	TEST(ft_isascii(INT_MAX), 0, INT_MAX);


	return (fail);

}