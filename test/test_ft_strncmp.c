/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 13:07:38 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 13:51:04 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

#define TEST(description, condition) do { \
	if (!(condition)) { \
		printf("Test failed: %s\n", description); \
		fail = 1; \
	} \
} while (0)

#define ASSERT_STR_EQ(a, b, description) do { \
	if (strcmp((a), (b)) != 0) { \
		printf("Test failed: %s\n", description); \
		fail = 1; \
	} \
} while (0)

int main ()
{
    int fail = 0;

    //TEST 1: retorna 0 se s1 e s2 são iguais
    const char s1[3] = "abc";
    const char s3[3] = "abc";

    int std_sd = strncmp(s1,s3, 3);
    int std_ft = ft_strncmp(s1,s3, 3);

    TEST("ft_strncmp should return 0", std_sd == std_ft);

    //TEST 2: diferença no inicio
    const char *d2 = "abc";
    const char *d3 = "abc";

    int std_sd1 = strncmp(d2,d3, 3);
    int std_ft1 = ft_strncmp(d2,d3, 3);

    TEST("strncmp should detect difference at the first character", std_sd1 == std_ft1);

    //TEST 3: Diferença no fim do range n
    const char *a3 = "abx";
    const char *b3 = "abc";
    int std3 = strncmp(a3, b3, 3);
    int ft3  = ft_strncmp(a3, b3, 3);
    TEST("strncmp should detect difference at the last character of n", std3 == ft3);

    //TEST 4: n menor que a primeira diferença
    const char *a4 = "abc";
    const char *b4 = "axc";
    int std4 = strncmp(a4, b4, 1);  // só compara 'a' vs 'a'
    int ft4  = ft_strncmp(a4, b4, 1);
    TEST("strncmp should stop before the difference when n is small", std4 == ft4);

    //TEST 5: n == 0, deve retornar 0 sempre
    const char *a5 = "abc";
    const char *b5 = "xyz";
    int std5 = strncmp(a5, b5, 0);
    int ft5  = ft_strncmp(a5, b5, 0);
    TEST("strncmp with n == 0 should return 0", std5 == ft5);

    //TEST 6: uma String menor com \0
    const char *a6 = "abc";
    const char *b6 = "abcdef";
    int std6 = strncmp(a6, b6, 6);
    int ft6  = ft_strncmp(a6, b6, 6);
    TEST("strncmp should treat shorter string with null terminator", std6 == ft6);

    // TEST 7: string vazia vs string não vazia
    const char *empty = "";
    const char *nonempty = "abc";
    TEST("strncmp empty vs non-empty", ft_strncmp(empty, nonempty, 3) == strncmp(empty, nonempty, 3));
    TEST("strncmp non-empty vs empty", ft_strncmp(nonempty, empty, 3) == strncmp(nonempty, empty, 3));

    // TEST 8: caracteres especiais / acentuação
    const char *spec1 = "ábc";
    const char *spec2 = "abc";
    TEST("strncmp com caracteres acentuados", ft_strncmp(spec1, spec2, 3) == strncmp(spec1, spec2, 3));

    // TEST 9: caracteres negativos (signed char)
    const char str_neg1[] = { (char)200, 'a', '\0' };
    const char str_neg2[] = { (char)150, 'a', '\0' };
    TEST("strncmp com caracteres negativos", ft_strncmp(str_neg1, str_neg2, 2) == strncmp(str_neg1, str_neg2, 2));

    // TEST 10: comparação com n maior que comprimento das strings
    const char *short1 = "abc";
    const char *short2 = "abcd";
    TEST("strncmp com n maior que comprimento", ft_strncmp(short1, short2, 10) == strncmp(short1, short2, 10));

    // TEST 11: strings muito longas
    size_t big_len = 1000;
    char big_str1[1001];
    char big_str2[1001];
    for (size_t i = 0; i < big_len; i++) {
        big_str1[i] = 'a';
        big_str2[i] = 'a';
    }
    big_str1[big_len] = '\0';
    big_str2[big_len] = '\0';
    TEST("strncmp com strings longas iguais", ft_strncmp(big_str1, big_str2, big_len) == 0);

    // Altera último caractere para diferença
    big_str2[big_len-1] = 'b';
    TEST("strncmp com strings longas diferentes no fim", ft_strncmp(big_str1, big_str2, big_len) == strncmp(big_str1, big_str2, big_len));
    

    return (fail);
}