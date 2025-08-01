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
}
