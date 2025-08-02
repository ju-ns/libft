/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:55:44 by marvin            #+#    #+#             */
/*   Updated: 2025/08/02 15:55:44 by marvin           ###   ########.fr       */
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

int main (){

    int fail = 0;

    //TEST 1: Concatenar com espaço suficiente
    char dst1[20] = "Hello, ";
    char dst2[20] = "Hello, ";
    const char *src = "World";

    size_t ret_std = strlcat(dst1, src, sizeof(dst1));
    size_t ret_ft = ft_strlcat(dst1, src, sizeof(dst2));

    ASSERT_STR_EQ(dst1, dst2, "ft_strlcat should produce the same final string");
    TEST("ft_strlcat should return the correct total length", ret_std == ret_ft);

    return (fail);
}