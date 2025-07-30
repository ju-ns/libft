/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:52:44 by marvin            #+#    #+#             */
/*   Updated: 2025/07/30 18:52:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

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

int main (void){
    int fail = 0;

    //TEST 1 - Comportamento básico
    char src[10] = "123456789";
    char dst1[10];
    char dst2[10];

    memcpy(dst1, src, 9);
    ft_memcpy(dst2, src, 9);

    ASSERT_MEM_EQ(dst1, dst2, 9, "ft_memcpy should copy 9 bytes from src to dst");

    //TEST 2 - copia os dados corretos
    
    char src2[] = {'A', '\0', 'B', '\0', 'C', '\0', 'D', '\0', 'E'};
    char dst[9];
    char expected[9];

    memcpy(expected, src2, 9);
    ft_memcpy(dst,  src2, 9);
    ASSERT_MEM_EQ(dst, expected, 9, "should copy 9 bytes from src");

    //TEST3 - copia 0 bytes, destino não deve mudar
    char src3[] = "Hello";
    char dst_1[] = "XXXXX";
    char dst_2[] = "XXXXX";

    memcpy(dst_1, src3, 0);
    ft_memcpy(dst_2, src3, 0);
    ASSERT_MEM_EQ(dst_1, dst_2, 5, "copy 0 bytes: should do nothing");

    //TEST4 - src e dst são o mesmo ponteiro

    char buffer[] = "ABCDE";
    char *data = buffer;
    char *dt = buffer;
    memcpy(data, dt, 5);
    ft_memcpy(data, dt, 5);
    ASSERT_MEM_EQ(data, dt, 5, "src == dst: should still succeed");

    //TEST 5 - ponteiros nulos com n == 0

    char *ptr1 = NULL;
    char *ptr2 = NULL;

    void *ret1 = memcpy(ptr1, ptr2, 0);
    void *ret2 = ft_memcpy(ptr1, ptr2, 0);

    ASSERT_TRUE(ret1 == ret2, "ft_memcpy(NULL, NULL, 0) returns same as memcpy");


    return (fail);
}
