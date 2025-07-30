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

	return (fail);
}
