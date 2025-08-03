/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 13:07:38 by marvin            #+#    #+#             */
/*   Updated: 2025/08/03 13:07:38 by marvin           ###   ########.fr       */
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



    return (fail);
}