/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:51:30 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 13:15:40 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

#define TEST(description, condition) do {\
    if(!(condition)) {\
        printf("Test failed: %s\n", description); \
        fail = 1; \
    } \
} while (0)

#define ASSERT_MEM_EQ(a, b, n, description) do {\
    if(memcmp((a), (b), (n)) != 0) { \
        printf("Test failed: %s\n", description); \
        fail = 1; \
    }\
} while(0)

#define ASSERT_TRUE(condition, description) do {\
    if(!(condition)) { \
        printf("Test failed: %s\n", description);\
        fail = 1; \
    }\
} while(0)

int main(void)
{
    int fail = 0;
    //TEST 1 - Cenário básico
    char var1[] = {'a','2','b','3'};
    char var2[] = {'a','2','b','3'};

    void *ret1 = memchr(var1, '2', 3);
    void *ret2 = ft_memchr(var2, '2', 3);

    TEST("Expected: 2", ret1 != NULL && ret2 != NULL);

    //TEST 2 - Não encontra o caractere 
    char str1[] = "abcdef";
    char str2[] = "abcdef";

    ret1 = memchr(str1, 'x', 6);
    ret2 = ft_memchr(str2, 'x', 6);

    TEST("Char not found returns NULL", ret1 == NULL && ret2 == NULL);

    //TEST 3 - Encontrar no final do range
    char str3[] = "12345";
    char str4[] = "12345";

    ret1 = memchr(str3, '5', 5);
    ret2 = ft_memchr(str4, '5', 5);

    TEST("Char found at last position of range", ret1 == str3 + 4 && ret2 == str4 + 4);

    //TEST 4 - n = 0, nada deve ser comparado
    char str5[] = "hello";
    char str6[] = "hello";

    ret1 = memchr(str5, 'e', 0);
    ret2 = ft_memchr(str6, 'e', 0);

    TEST("n = 0 must return NULL", ret1 == NULL && ret2 == NULL);

    //TEST 5 - Caracteres não ASCII (verifique que trata como unsigned char)

    char str7[] = {1,2,128,255};
    char str8[] = {1,2,128,255};

    ret1 = memchr(str7, 128, 4);
    ret2 = ft_memchr(str8, 128, 4);

    TEST("Usigned char match (128)", ret1 == str7 + 2 && ret2 == str8 + 2);

     // TEST 6 - Char encontrado na primeira posição
    char str_first[] = "abc";
    char str_first_copy[] = "abc";

    ret1 = memchr(str_first, 'a', 3);
    ret2 = ft_memchr(str_first_copy, 'a', 3);

    TEST("Char found at first position", ret1 == str_first && ret2 == str_first_copy);

    // TEST 7 - Buffer vazio com n=0
    char empty[] = "";

    ret1 = memchr(empty, 'a', 0);
    ret2 = ft_memchr(empty, 'a', 0);

    TEST("Empty buffer with n=0 returns NULL", ret1 == NULL && ret2 == NULL);

    // TEST 8 - Char -1 (255 unsigned)
    char arr_neg[] = {0, 255, 10};
    char arr_neg_copy[] = {0, 255, 10};

    ret1 = memchr(arr_neg, -1, 3);
    ret2 = ft_memchr(arr_neg_copy, -1, 3);

    TEST("Char -1 treated as 255 unsigned", ret1 == arr_neg + 1 && ret2 == arr_neg_copy + 1);

    // TEST 9 - Múltiplas ocorrências, deve retornar a primeira
    char multi[] = "abacada";
    char multi_copy[] = "abacada";

    ret1 = memchr(multi, 'a', 7);
    ret2 = ft_memchr(multi_copy, 'a', 7);

    TEST("Multiple occurrences returns first", ret1 == multi && ret2 == multi_copy);

    // TEST 10 - Char aparece fora do range n
    char outside[] = "abcdefg";
    char outside_copy[] = "abcdefg";

    ret1 = memchr(outside, 'g', 6);
    ret2 = ft_memchr(outside_copy, 'g', 6);

    TEST("Char outside range returns NULL", ret1 == NULL && ret2 == NULL);

    return (fail);
}