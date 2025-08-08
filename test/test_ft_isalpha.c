/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:28:19 by jnogueir          #+#    #+#             */
/*   Updated: 2025/07/25 13:18:05 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <assert.h> 

#define TEST(passed, expected, input) do { \
	int result = (passed); \
	if(result != (expected)) { \
		printf("Test failed: expected %d, got %d for input '%c'\n", (expected), result, (input)); \
		fail = 1; \
	} \
} while (0)

int main (void) {

	int fail = 0;
	TEST(ft_isalpha('A'), 1, 'A');
	TEST(ft_isalpha('Z'), 1, 'Z');

	TEST(ft_isalpha('a'), 1, 'a');
	TEST(ft_isalpha('z'), 1, 'z');

	TEST(ft_isalpha('0'), 0, '0');
	TEST(ft_isalpha('9'), 0, '9');

	TEST(ft_isalpha('@'), 0, '@');
	TEST(ft_isalpha('['), 0, '[');
	TEST(ft_isalpha('#'), 0, '#');

	TEST(ft_isalpha(' '), 0, ' ');
	TEST(ft_isalpha('\t'), 0, '\t');

	TEST(ft_isalpha(0), 0, 0);
	TEST(ft_isalpha(127), 0, 127);
	TEST(ft_isalpha(-1), 0, -1);
	TEST(ft_isalpha(255), 0, 255);

	// Testa todas as letras maiúsculas e minúsculas
	for (int c = 'A'; c <= 'Z'; c++) {
		TEST(ft_isalpha(c), 1, c);
	}
	for (int c = 'a'; c <= 'z'; c++) {
		TEST(ft_isalpha(c), 1, c);
	}

	// Caracteres próximos ao alfabeto
	TEST(ft_isalpha('^'), 0, '^');
	TEST(ft_isalpha('`'), 0, '`');
	TEST(ft_isalpha('{'), 0, '{');
	TEST(ft_isalpha('|'), 0, '|');

	// Caracteres de controle adicionais
	TEST(ft_isalpha('\n'), 0, '\n');
	TEST(ft_isalpha('\r'), 0, '\r');
	TEST(ft_isalpha('\b'), 0, '\b');

	// Valores extremos adicionais
	TEST(ft_isalpha(-128), 0, -128);
	TEST(ft_isalpha(256), 0, 256);

	// Testa caractere nulo explicitamente
	TEST(ft_isalpha('\0'), 0, '\0');


	return (fail);
}
