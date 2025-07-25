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

	return (fail);

}