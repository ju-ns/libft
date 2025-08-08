/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:23:07 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 13:40:10 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


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
    //TEST 1: string simples
    const char *s1 = "libft42";
    char *std_sd = strdup(s1);
    char *std_ft = ft_strdup(s1);

    ASSERT_STR_EQ(std_sd, std_ft, "ft_strdup should copy string exactly");
	TEST("ft_strdup should return a new pointer", std_ft != s1);
    free(std_sd);
    free(std_ft);

    //TEST 2: string vazia 
    const char *s2 = "";
    char *std2 = strdup(s2);
    char *ft2 = ft_strdup(s2);

    ASSERT_STR_EQ(std2, ft2, "ft_strdup should handle empty string");
    TEST("ft_strdup should return a new pointer", ft2 != s2);

    free(std2);
    free(ft2);

    //TEST 3: string com espaços e caracteres especiais 
    const char *s3 = " \tHello!\n42💻";
    char *std3 = strdup(s3);
    char *ft3 = ft_strdup(s3);

    ASSERT_STR_EQ(std3, ft3, "ft_strdup should handle spaces and special chars");
    TEST("ft_strdup should return a new pointer", ft3 != s3);

    free(std3);
    free(ft3);

    //TEST 4: string longa 
    const char *s4 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char *std4 = strdup(s4);
    char *ft4 = ft_strdup(s4);

    ASSERT_STR_EQ(std4, ft4, "ft_strdup should handle long strings");
    TEST("ft_strdup should return a new pointer", ft4 != s4);

    free(std4);
    free(ft4);

    //TEST 5: verificação de ponteiro nulo 
    char *ft5 = ft_strdup("test");
    TEST("ft_strdup should not return NULL", ft5 != NULL);
    free(ft5);

    // TEST 6: string com \0 no meio (simulado via array)
    const char s6[] = {'A', 'B', '\0', 'C'};
    char *ft6 = ft_strdup(s6);
    TEST("ft_strdup should stop at first null terminator", ft6[0] == 'A' && ft6[1] == 'B' && ft6[2] == '\0');
    TEST("ft_strdup copied string should be null terminated", ft6[strlen(ft6)] == '\0');
    free(ft6);

    // TEST 7: string com múltiplas linhas
    const char *s7 = "Linha1\nLinha2\nLinha3";
    char *ft7 = ft_strdup(s7);
    ASSERT_STR_EQ(ft7, s7, "ft_strdup should handle multiline strings");
    free(ft7);

    // TEST 8: string literal const
    const char *s8 = "constante";
    char *ft8 = ft_strdup(s8);
    ASSERT_STR_EQ(ft8, s8, "ft_strdup should duplicate const strings");
    TEST("ft_strdup should return new pointer for const string", ft8 != s8);
    free(ft8);

    // TEST 9: comparar tamanho da string duplicada
    const char *s9 = "tamanho";
    char *ft9 = ft_strdup(s9);
    TEST("ft_strdup copied string should have same length", strlen(ft9) == strlen(s9));
    free(ft9);

    return (fail);
}

