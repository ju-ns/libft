/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 23:54:16 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 13:55:13 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

int main(void)
{
	int fail = 0;

	// TEST 1: Substring do meio da string
	const char *src = "libft42";
	char *sub = ft_substr(src, 2, 3);  // deve pegar "bft"

	ASSERT_STR_EQ(sub, "bft", "ft_substr should extract substring correctly");
	free(sub);

    //TEST 2: start maior que tamanho da string
    const char *src2 = "42sp";
    char *sub2 = ft_substr(src2, 10, 3);  // start está fora

    ASSERT_STR_EQ(sub2, "", "ft_substr should return empty string if start > strlen");
    free(sub2);

    //TEST 3: len maior que o resto da string 
    const char *src3 = "libft";
    char *sub3 = ft_substr(src3, 3, 10);  // só resta "ft"

    ASSERT_STR_EQ(sub3, "ft", "ft_substr should not overflow past the end of the string");
    free(sub3);

    //TEST 4: len == 0
    const char *src4 = "libft";
    char *sub4 = ft_substr(src4, 2, 0);  // nenhuma letra

    ASSERT_STR_EQ(sub4, "", "ft_substr with len = 0 should return empty string");
    free(sub4);

    //TEST 5: substring completa da string
    const char *src5 = "complete";
    char *sub5 = ft_substr(src5, 0, ft_strlen(src5));

    ASSERT_STR_EQ(sub5, "complete", "ft_substr should return full copy if len = strlen");
    TEST("ft_substr should not return same pointer", sub5 != src5);
    free(sub5);

    // TEST 6: src vazia
    const char *src6 = "";
    char *sub6 = ft_substr(src6, 0, 5);
    ASSERT_STR_EQ(sub6, "", "ft_substr with empty src should return empty string");
    free(sub6);

    // TEST 7: start == strlen(src)
    const char *src7 = "libft";
    char *sub7 = ft_substr(src7, ft_strlen(src7), 3);
    ASSERT_STR_EQ(sub7, "", "ft_substr with start == strlen(src) should return empty string");
    free(sub7);

    // TEST 8: len muito grande, start == 0
    const char *src8 = "teststring";
    char *sub8 = ft_substr(src8, 0, 1000);
    ASSERT_STR_EQ(sub8, "teststring", "ft_substr with large len and start 0 should return full string");
    free(sub8);

    // TEST 9: len == tamanho da string, start > 0
    const char *src9 = "teststring";
    char *sub9 = ft_substr(src9, 4, ft_strlen(src9));
    ASSERT_STR_EQ(sub9, "string", "ft_substr with len > remaining length should return till end");
    free(sub9);
	return (fail);
}
