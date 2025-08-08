/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:19:36 by jnogueir          #+#    #+#             */
/*   Updated: 2025/07/25 13:26:37 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

#define TEST(passed, expected, input) do { \
	int result = (passed); \
	if(result != (expected)) { \
		printf("Test failed: expected %d, got %d for input '%c'\n", (expected), result, (input)); \
		fail = 1; \
	} \
} while (0)

int main (){

	int fail = 0;

	TEST(ft_isprint(32), 1, 32);
	TEST(ft_isprint(126), 1, 126);

	TEST(ft_isprint(65), 1, 65);
	TEST(ft_isprint(97), 1, 97);
	TEST(ft_isprint(48), 1, 48);
	TEST(ft_isprint(33), 1, 33);

	TEST(ft_isprint(31), 0, 31);
	TEST(ft_isprint(10), 0, 10);
	TEST(ft_isprint(0), 0, 0);

	TEST(ft_isprint(127), 0, 127);
	TEST(ft_isprint(200), 0, 200);
	TEST(ft_isprint(255), 0, 255);

	TEST(ft_isprint(-1), 0, -1);
	TEST(ft_isprint(-42), 0, -42);
	TEST(ft_isprint(300), 0, 300);

	// Testa toda a faixa imprimível
	for (int c = 32; c <= 126; c++) {
		TEST(ft_isprint(c), 1, c);
	}

	// Caracteres de controle adicionais
	TEST(ft_isprint('\r'), 0, '\r');
	TEST(ft_isprint('\t'), 0, '\t');
	TEST(ft_isprint('\b'), 0, '\b');

	// Valores extremos
	TEST(ft_isprint(INT_MIN), 0, INT_MIN);
	TEST(ft_isprint(INT_MAX), 0, INT_MAX);


	return (fail);
}
