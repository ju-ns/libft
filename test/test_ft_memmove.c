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

int main (void)
{
    int fail = 0;
    //TEST 1 - Cópia básica, sem sobreposição
    char src[] = "123456789";
    char dst1[10];
    char dst2[10];

    memove(dst1, src, 9);
    ft_memove(dst2, src, 9);
    ASSERT_MEM_EQ(dst1, dst2, 9, "ft_memove should copy 9 bytes correctly");
    
    return (fail);
}