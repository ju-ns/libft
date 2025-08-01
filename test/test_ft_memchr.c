/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:51:30 by marvin            #+#    #+#             */
/*   Updated: 2025/07/31 23:51:30 by marvin           ###   ########.fr       */
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

    
    return (fail);
}