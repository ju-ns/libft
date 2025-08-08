/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:24:00 by jnogueir          #+#    #+#             */
/*   Updated: 2025/07/25 12:37:56 by jnogueir         ###   ########.fr       */
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

int main (void)
{
	int fail = 0;

	TEST(ft_isdigit('5'), 1, '5');
	TEST(ft_isdigit('0'), 1, '0');
	TEST(ft_isdigit('9'), 1, '9');

	TEST(ft_isdigit('a'), 0, 'a');
	TEST(ft_isdigit('z'), 0, 'z');
	TEST(ft_isdigit('B'), 0, 'B');

	TEST(ft_isdigit('!'), 0, '!');
	TEST(ft_isdigit(' '), 0, ' ');
	TEST(ft_isdigit('@'), 0, '@');

	TEST(ft_isdigit(127), 0, 127);
	TEST(ft_isdigit(-1), 0, -1);

	TEST(ft_isdigit(48), 1, 48);
	TEST(ft_isdigit(57), 1, 57);

	// Testa todos os dígitos de '0' a '9'
	for (char c = '0'; c <= '9'; c++) {
		TEST(ft_isdigit(c), 1, c);
	}

	// Testa caracteres próximos ao intervalo de dígitos
	TEST(ft_isdigit('/'), 0, '/');
	TEST(ft_isdigit(':'), 0, ':');

	// Testa caracteres de controle e nulo
	TEST(ft_isdigit('\0'), 0, '\0');
	TEST(ft_isdigit('\n'), 0, '\n');
	TEST(ft_isdigit('\t'), 0, '\t');

	// Testa valores extremos
	TEST(ft_isdigit(INT_MIN), 0, INT_MIN);
	TEST(ft_isdigit(INT_MAX), 0, INT_MAX);

	return (fail);
}

