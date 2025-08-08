/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:13:09 by jnogueir          #+#    #+#             */
/*   Updated: 2025/07/25 15:06:19 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

#define TEST(description, condition) do { \
	if((!condition)) { \
		printf("Test failed: %s\n", description); \
		fail = 1; \
	} \
} while (0)

#define ASSERT_MEM_EQ(a, b, n, description) do { \
	if(memcmp((a), (b), (n)) != 0) { \
		printf("Test failed: %s\n", description); \
		fail = 1; \
	}\
} while (0)

int main (void)
{
	int fail = 0;
	unsigned char buf1[10];
	unsigned char buf2[10];

	//TEST 1 - main feature bzero
	memset(buf1, 42, 10);
	memset(buf2, 42, 10);

	ft_bzero(buf1, 10);
	bzero(buf2, 10);
	ASSERT_MEM_EQ(buf1, buf2, 10, "ft_bzero deve zerar igual ao bzero");
	
	//TEST 2 - n = 0 (should not change the buffer)
	memset(buf1, 55, 10);
	memset(buf2, 55, 10);
	
	ft_bzero(buf1, (0));
	bzero(buf2, (0));
	ASSERT_MEM_EQ(buf1, buf2, 10, "ft_bzero com n=0 não deve alterar o buffer");

	 // TEST 3 - zerar parcialmente (5 bytes)
    memset(buf1, 100, 10);
    memset(buf2, 100, 10);
    ft_bzero(buf1, 5);
    bzero(buf2, 5);
    ASSERT_MEM_EQ(buf1, buf2, 10, "ft_bzero deve zerar parcialmente (5 bytes)");

    // TEST 4 - buffer já zerado antes
    memset(buf1, 0, 10);
    memset(buf2, 0, 10);
    ft_bzero(buf1, 10);
    bzero(buf2, 10);
    ASSERT_MEM_EQ(buf1, buf2, 10, "ft_bzero em buffer já zerado");

    // TEST 5 - buffer grande (1000 bytes)
    unsigned char big1[1000];
    unsigned char big2[1000];
    memset(big1, 77, 1000);
    memset(big2, 77, 1000);
    ft_bzero(big1, 1000);
    bzero(big2, 1000);
    ASSERT_MEM_EQ(big1, big2, 1000, "ft_bzero em buffer grande");

	return (fail);
}