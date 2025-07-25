/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:13:09 by jnogueir          #+#    #+#             */
/*   Updated: 2025/07/25 14:31:53 by jnogueir         ###   ########.fr       */
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

#define ASSER_MEM_EQ(a, b, n, description) do { \
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

	memset(buf1, 42, 10);
	memset(buf2, 42, 10);
	
	ft_bzero(buf1, 10);
	bzero(buf2, 10);

	ASSER_MEM_EQ(buf1, buf2, 10, "ft_bzero deve zerar igual ao bzero");
	return (fail);
	
	
}