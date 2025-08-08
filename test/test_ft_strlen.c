/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 02:07:26 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 13:48:35 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>


#define TEST(description, condition) do { \
	if (!(condition)) { \
		printf("Test failed: %s\n", description); \
		fail = 1; \
	} \
} while (0)

int main(void) {
	int fail = 0;

	// TEST 1: String vazia
	TEST("ft_strlen(\"\") should return 0", ft_strlen("") == strlen(""));

	// TEST 2: Um caractere
	TEST("ft_strlen(\"a\") should return 1", ft_strlen("a") == strlen("a"));

	// TEST 3: String comum
	TEST("ft_strlen(\"hello\") should return 5", ft_strlen("hello") == strlen("hello"));

	// TEST 4: Espaços e símbolos
	TEST("ft_strlen(\"com espaços!\")", ft_strlen("com espaços!") == strlen("com espaços!"));

	// TEST 5: String longa
	TEST("ft_strlen(\"1234567890abcdefghij\")", ft_strlen("1234567890abcdefghij") == strlen("1234567890abcdefghij"));

	// TEST 6: String com caracteres UTF-8 multibyte (emojis, acentos)
	const char *utf8_str = "Olá 😊";
	TEST("ft_strlen conta bytes, não caracteres", ft_strlen(utf8_str) == strlen(utf8_str));

	// TEST 7: String com \0 no meio - strlen para na primeira ocorrência do nulo
	char str_with_null[] = {'a','b','\0','c','d','\0'};
	TEST("ft_strlen para no primeiro \\0", ft_strlen(str_with_null) == strlen(str_with_null));

	return (fail);
}