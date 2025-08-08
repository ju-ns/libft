/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:47:48 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 13:19:57 by jnogueir         ###   ########.fr       */
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

    // TEST 5 - Sobreposição pequena, dest = src + 1
    char buf1[] = "123456789";
    char buf2[] = "123456789";

    memmove(buf1 + 1, buf1, 8);
    ft_memmove(buf2 + 1, buf2, 8);
    ASSERT_MEM_EQ(buf1, buf2, 9, "Overlap: dest = src + 1");

    // TEST 6 - Cópia com bytes nulos no meio
    char src_null[] = {'A', 0, 'B', 0, 'C'};
    char dst_std[5];
    char dst_ft[5];

    memmove(dst_std, src_null, 5);
    ft_memmove(dst_ft, src_null, 5);
    ASSERT_MEM_EQ(dst_std, dst_ft, 5, "Copy with null bytes");

    // TEST 7 - Copiar 1 byte com sobreposição
    char small1[] = "AB";
    char small2[] = "AB";

    memmove(small1 + 1, small1, 1);
    ft_memmove(small2 + 1, small2, 1);
    ASSERT_MEM_EQ(small1, small2, 2, "Overlap copy of 1 byte");

    // TEST 8 - Verificar retorno da função
    char ret_src[] = "ReturnTest";
    char ret_dst[20];

    void *ret_std_ptr = memmove(ret_dst, ret_src, 10);
    void *ret_ft_ptr = ft_memmove(ret_dst, ret_src, 10);

    TEST("ft_memmove returns destination pointer", ret_ft_ptr == ret_dst);
    TEST("memmove returns destination pointer", ret_std_ptr == ret_dst);

    return (fail);
}