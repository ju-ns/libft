/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:01:28 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/05 13:06:47 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define TEST(desc, cond) do { \
	if (!(cond)) { \
		printf("Test failed: %s\n", desc); \
		fail = 1; \
	} \
} while (0)

#define ASSERT_ZEROED(ptr, size, desc) do { \
	size_t i; \
	int failed = 0; \
	for (i = 0; i < (size); i++) { \
		if (((unsigned char *)ptr)[i] != 0) { \
			failed = 1; \
			break; \
		} \
	} \
	if (failed) { \
		printf("Test failed: %s\nMemory not zeroed\n", desc); \
		fail = 1; \
	} \
} while (0)

int main(void)
{
	int fail = 0;

	// TESTE 1: alocação de 5 ints
	int *a = (int *)ft_calloc(5, sizeof(int));
	TEST("ft_calloc deve retornar ponteiro válido", a != NULL);
	ASSERT_ZEROED(a, 5 * sizeof(int), "ft_calloc deve zerar os 5 ints");
	free(a);

	// TESTE 2: comparação com calloc da libc
	char *b1 = (char *)ft_calloc(10, 1);
	char *b2 = (char *)calloc(10, 1);
	TEST("ft_calloc deve se comportar igual ao calloc", b1 && b2 && memcmp(b1, b2, 10) == 0);
	free(b1);
	free(b2);

	// TESTE 3: count ou size zero deve retornar ponteiro válido ou NULL (ambos válidos)
	void *c = ft_calloc(0, 5);
	TEST("ft_calloc com count 0 não deve crashar", 1);
	free(c);

	// TESTE 4: proteção contra overflow
	void *d = ft_calloc(SIZE_MAX, SIZE_MAX);
	TEST("ft_calloc com overflow deve retornar NULL", d == NULL);

	// TESTE 5: alocação de 1 byte
    char *e = (char *)ft_calloc(1, 1);
    TEST("ft_calloc aloca 1 byte válido", e != NULL);
    ASSERT_ZEROED(e, 1, "ft_calloc deve zerar 1 byte");
    free(e);

    // TESTE 6: alocação de 1000 ints
    int *f = (int *)ft_calloc(1000, sizeof(int));
    TEST("ft_calloc aloca 1000 ints", f != NULL);
    ASSERT_ZEROED(f, 1000 * sizeof(int), "ft_calloc deve zerar 1000 ints");
    free(f);

    // TESTE 7: teste de ponteiros diferentes em chamadas separadas
    void *g1 = ft_calloc(10, 1);
    void *g2 = ft_calloc(10, 1);
    TEST("ft_calloc retorna ponteiros diferentes em chamadas diferentes", g1 != g2);
    free(g1);
    free(g2);

    // TESTE 8: calloc(0, 0) explicitamente
    void *h = ft_calloc(0, 0);
    TEST("ft_calloc com 0,0 não deve crashar", 1);
    free(h);

	return (fail);
}