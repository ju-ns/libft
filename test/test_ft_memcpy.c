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

    return (fail);
}

