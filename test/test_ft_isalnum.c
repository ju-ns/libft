/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:40:08 by jnogueir          #+#    #+#             */
/*   Updated: 2025/07/25 12:37:06 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

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

	TEST(ft_isalnum('2'), 1, '2');
	TEST(ft_isalnum(2), 0, 2);
	TEST(ft_isalnum('\n'), 0, '\n');
	TEST(ft_isalnum('A'), 1, 'A');
	TEST(ft_isalnum('z'), 1, 'z');
	TEST(ft_isalnum('$'), 0, '$');
	TEST(ft_isalnum(' '), 0, ' ');
	TEST(ft_isalnum('9'), 1, '9');

	// Testa todos os dígitos de '0' a '9'
	for (char c = '0'; c <= '9'; c++) {
		TEST(ft_isalnum(c), 1, c);
	}

	// Letras adicionais maiúsculas e minúsculas
	TEST(ft_isalnum('M'), 1, 'M');
	TEST(ft_isalnum('m'), 1, 'm');

	// Caracteres próximos do alfanumérico
	TEST(ft_isalnum('@'), 0, '@');
	TEST(ft_isalnum('['), 0, '[');
	TEST(ft_isalnum('`'), 0, '`');
	TEST(ft_isalnum('{'), 0, '{');

	// Caracteres especiais e limites
	TEST(ft_isalnum('\0'), 0, '\0');
	TEST(ft_isalnum('\t'), 0, '\t');
	TEST(ft_isalnum('\r'), 0, '\r');

	// Valores fora do intervalo ASCII imprimível (atenção: pode gerar warning)
	TEST(ft_isalnum(-1), 0, -1);
	TEST(ft_isalnum(128), 0, 128);


	return (fail);
}
