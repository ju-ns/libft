/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:20:18 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/05 13:20:18 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>


#define TEST(description, condition) do {\
	if ((!(condition))) { \
		printf("Test failed: %s\n ", description); \
		fail = 1; \
	}\
}while(0)

#define ASSERT_MEM_EQ(a, b, n, description) do { \
	if(memcmp((a), (b), (n)) != 0) {\
		printf("Test failed: %s\n ", description); \
		fail = 1; \
	}\
} while(0)

#define ASSERT_TRUE(condition, description) do { \
	if(!(condition)) { \
		printf("Test failed: %s\n", description); \
		fail = 1; \
	} \
} while (0)

int main (){
	int fail = 0;
	unsigned char buffer1[10];
	unsigned char buffer2[10];

	//TEST1 - Comportamento básico
	memset(buffer1, 'X', 4);
	ft_memset(buffer2, 'X', 4);
	ASSERT_MEM_EQ(buffer1, buffer2, 4, "ft_memset should fill with 'X' correctly");

	//TEST2 - Len parcial
	memset(buffer1, 'B', 5);
	ft_memset(buffer2, 'B', 5);
	ASSERT_MEM_EQ(buffer1, buffer2, 5, "ft_memset should fill 5 bytes with 'B'");

	//TEST3 - len = 0 (nada muda)
	memset(buffer1, 'C', 10);
	memset(buffer2, 'C', 10);

	size_t len = 0;
	ft_memset(buffer1, 'X', len);
	memset(buffer2, 'X', len);
	ASSERT_MEM_EQ(buffer1, buffer2, 10, "ft_memset with len = 0 should not change");

	//TEST4 - informa o ponto de partida
	memset(buffer1 + 2, 'X', 2);
	ft_memset(buffer2 + 2, 'X', 2);
	ASSERT_MEM_EQ(buffer1 + 2, buffer2 + 2, 2, "ft_memset must fill from the index two");

	//TEST5 - preenchimento parcial (primeiros bytes)
	memset(buffer1, 'A', 10);
	ft_memset(buffer2, 'A', 10);

	memset(buffer1, 'B', 3);
	ft_memset(buffer2, 'B', 3);

	ASSERT_MEM_EQ(buffer1, buffer2, 10, "ft_memset must overwrite only the first 3 bytes");

	// TEST6 - caractere negativo (ex: -1 = 0xFF)
	memset(buffer1, 0, 10);
	ft_memset(buffer2, 0, 10);

	ft_memset(buffer1, -1, 10);
	memset(buffer2, -1, 10);
	ASSERT_MEM_EQ(buffer1, buffer2, 10, "ft_memset with negative char value (0xFF)");

	//TEST7 - retorno da função 
	char data[5];
	void *ret = ft_memset(data, 'Z', 5);

	ASSERT_TRUE(ret == data, "ft_memset must return the original pointer");

	// TEST8 - Preencher buffer maior parcialmente
	char bigbuf1[20], bigbuf2[20];
	memset(bigbuf1, 'A', 20);
	ft_memset(bigbuf2, 'A', 20);
	ft_memset(bigbuf1, 'Z', 15);
	memset(bigbuf2, 'Z', 15);
	ASSERT_MEM_EQ(bigbuf1, bigbuf2, 20, "Partial fill of 15 bytes in 20 byte buffer");

	// TEST9 - Preencher buffer com zero
	char zero1[10], zero2[10];
	memset(zero1, 'X', 10);
	ft_memset(zero2, 'X', 10);
	ft_memset(zero1, 0, 10);
	memset(zero2, 0, 10);
	ASSERT_MEM_EQ(zero1, zero2, 10, "Fill buffer with zero bytes");

	// TEST10 - Retorno do ponteiro sempre correto
	char retbuf[5];
	char *r1 = ft_memset(retbuf, 'Q', 5);
	char *r2 = ft_memset(retbuf, 'W', 0);
	TEST("ft_memset returns correct pointer", r1 == retbuf && r2 == retbuf);


	return (fail);
}