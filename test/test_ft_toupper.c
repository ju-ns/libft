/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:28:36 by jnogueir          #+#    #+#             */
/*   Updated: 2025/07/25 14:06:29 by jnogueir         ###   ########.fr       */
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

int main ()
{
	int	fail = 0;

	TEST(ft_toupper('a'), 'A', 'a');
	TEST(ft_toupper('b'), 'B', 'b');
	TEST(ft_toupper('z'), 'Z', 'z');

	TEST(ft_toupper('A'), 'A', 'A');
	TEST(ft_toupper('Z'), 'Z', 'Z');

	TEST(ft_toupper('0'), '0', '0');
	TEST(ft_toupper('9'), '9', '9');

	TEST(ft_toupper('@'), '@', '@');
	TEST(ft_toupper('['), '[', '[');
	TEST(ft_toupper('!'), '!', '!');

	TEST(ft_toupper(0), 0, 0);
	TEST(ft_toupper(127), 127, 127);

	TEST(ft_toupper(-1), -1, -1);
	TEST(ft_toupper(255), 255, 255);

	return (fail);
}

