/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:43:10 by marvin            #+#    #+#             */
/*   Updated: 2025/08/01 12:43:10 by marvin           ###   ########.fr       */
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

int main (void){
    int fail = 0;

    char src[] = "libft42";
    char dst1[20];
    char dst2[20];

    size_t ret_std = strlcpy(dst1, src, sizeof(dst1));
    size_t ret_ft = ft_strlcpy(dst2, src, sizeof(dst2));

    ASSERT_STR_EQ(dst1, dst2, "strlcpy should copy correctly with large enough buffer");
    TEST("strlcpy should return length of src", ret_std == ret_ft);

    //TEST 2: Buffer menor que src - deve copiar parcialmente e terminar com \0

    char src2[] = "42RioSP";
    char dst_std2[5];
    char dst_ft2[5];

    size_t ret_std2 = strlcpy(dst_std2, src2, sizeof(dst_std2));
    size_t ret_ft2 = ft_strlcpy(dst_ft2, src2, sizeof(dst_ft2));

    ASSERT_STR_EQ(dst_std2, dst_ft2, "strlcpy should copy partialy with null termination");
    TEST("strlcpy should return full length of src even if truncated", ret_std2 == ret_ft2);

    //TEST 3: size = 0 - não deve copiar nada, retornar apenas o tamanho de src

    char src3[] = "libft";
    char dst_std3[] = "XXXXX";
    char dst_ft3[] = "XXXXX";

    size_t ret_std3 = strlcpy(dst_std3, src3, 0);
    size_t ret_ft3 = ft_strlcpy(dst_ft3, src3, 0);

    ASSERT_STR_EQ(dst_std3, dst_ft3, "strclpy with size 0 must not copy");
    TEST("strlcpy with size 0 must return length of src", ret_std3 == ret_ft3);

    //TEST 4: src vazia - deve escrever apenas \0 retorna 0
    char src4[] = "";
    char dst_std4[10] = "AAAAAAAAAA";
    char dst_ft4[10] = "AAAAAAAAAA";

    size_t ret_std4 = strlcpy(dst_std4, src4, sizeof(dst_std4));
    size_t ret_ft4 = ft_strlcpy(dst_ft4, src4, sizeof(dst_std4));

    ASSERT_STR_EQ(dst_std4, dst_ft4, "strclpy with empty src should write just \0 and return 0");
    TEST("strlcpy with empty src should return 0", ret_std4 == ret_ft4);





    return (fail);
}
