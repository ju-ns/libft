/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:28:52 by jnogueir          #+#    #+#             */
/*   Updated: 2025/07/25 13:33:31 by jnogueir         ###   ########.fr       */
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

int main (){
	
	int fail = 0;

	TEST(ft_tolower('A'), 'a', 'A');
	TEST(ft_tolower('B'), 'b', 'B');
	TEST(ft_tolower('Z'), 'z', 'Z');

	TEST(ft_tolower('a'), 'a', 'a');
	TEST(ft_tolower('z'), 'z', 'z');

	TEST(ft_tolower('0'), '0', '0');
	TEST(ft_tolower('9'), '9', '9');

	TEST(ft_tolower('@'), '@', '@');
	TEST(ft_tolower('['), '[', '[');
	TEST(ft_tolower('!'), '!', '!');

	TEST(ft_tolower(0), 0, 0);
	TEST(ft_tolower(127), 127, 127);

	TEST(ft_tolower(-1), -1, -1);
	TEST(ft_tolower(255), 255, 255);

	return (fail);
}