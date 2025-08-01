/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:47:48 by marvin            #+#    #+#             */
/*   Updated: 2025/07/30 20:47:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

#define TEST(description, condition) do { \
    if(!(condition)) {\
        printf("Test failed: %s\n", description); \
        fail = 1; \
    } \
} while (0)

#define ASSERT_MEM_EQ(a, b, n, description) do {\
    if(memcmp((a), (b), (n)) != 0){\
        printf("Test failed: %s\n", description);\
        fail = 1; \
    }\
} while(0)

#define ASSERT_TRUE(condition, description) do {\
    if(!(condition)) { \
        printf("Test failed: %s\n", description);\
        fail = 1; \
    }\
} while(0)

int main (void)
{
    int fail = 0;
    //TEST 1 - Cópia básica, sem sobreposição
    char src[] = "123456789";
    char dst1[10];
    char dst2[10];

    memmove(dst1, src, 9);
    ft_memmove(dst2, src, 9);
    ASSERT_MEM_EQ(dst1, dst2, 9, "ft_memove should copy 9 bytes correctly");
    
    //TEST 2 - Copiar bytes para uma posição anterior da mesma área (destino < origem)

    char buff1[] = "123456789";
    char buff2[] = "123456789";

    memmove(buff1, buff1 + 2, 7);
    ft_memmove(buff2, buff2 + 2, 7);

    ASSERT_MEM_EQ(buff1, buff2, 9, "Overlap: dest before src");

    //TEST 3 - ponteiros NULL com n = 0
    char *ptr1 = NULL;
    char *ptr2 = NULL;

    void *ret1 = memmove(ptr1, ptr1, 0);
    void *ret2 = ft_memmove(ptr2, ptr2, 0);

    ASSERT_TRUE(ret1 == ret2, "NULL pointers with length 0");

    //TEST 4 - Sobreposição para trás 
    char buffer1[] = "ABCDABCDEEFGHIJ";
    char buffer2[] = "ABCDABCDEEFGHIJ";

    memmove(buffer1 + 4, buffer1, 10);
    ft_memmove(buffer2 + 4, buffer2, 10);

    ASSERT_MEM_EQ(buffer1, buffer2, 10, "Expected result: ABCDABCDEF");

    return (fail);
}