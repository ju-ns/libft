/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:55:44 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 16:11:14 by jnogueir         ###   ########.fr       */
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

static size_t strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t	dlen = 0;
	size_t	slen = 0;
	size_t	i = 0;

	if (!dst || !src)
		return (0);

	// Calcula comprimento de dst e src
	while (dst[dlen] && dlen < dstsize)
		dlen++;
	while (src[slen])
		slen++;

	// Se dlen já passou do limite, não copia nada
	if (dlen == dstsize)
		return (dstsize + slen);

	// Copia src no final de dst até preencher o espaço
	while (src[i] && (dlen + i + 1) < dstsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}

	dst[dlen + i] = '\0';
	return (dlen + slen);
}

int main (){

    int fail = 0;

    //TEST 1: Concatenar com espaço suficiente
    char dst1[20] = "Hello, ";
    char dst2[20] = "Hello, ";
    const char *src = "World";

    size_t ret_std = strlcat(dst1, src, sizeof(dst1));
    size_t ret_ft = ft_strlcat(dst2, src, sizeof(dst2));

    ASSERT_STR_EQ(dst1, dst2, "ft_strlcat should produce the same final string");
    TEST("ft_strlcat should return the correct total length", ret_std == ret_ft);

    //TEST 2: Concatenar com espaço insuficiente
    char dst3[10] = "ABC";
    char dst4[10] = "ABC";
    const char *src1 = "DEFGHIJKL";

    size_t ret_std_b = strlcat(dst3, src1, 6);
    size_t ret_ft_b = ft_strlcat(dst4, src1, 6);

    ASSERT_STR_EQ(dst3, dst4, "strlcat should truncate when buffer is too small");
    TEST("strlcat should return length of src + min (size, dst_len)", ret_std_b == ret_ft_b);

    //TEST 3:  size = 0
    char dst5[10] = "ignore";
    char dst6[10] = "ignore";
    const char *src2 = "HELLO";

    size_t ret_std_c = strlcat(dst5, src2, 0);
    size_t ret_ft_c = ft_strlcat(dst6, src2, 0);

    TEST("strlcat with size 0 must return strlen(src)", ret_std_c == ret_ft_c);

    //TEST 4: src vazia
    char dst7[10] = "ignore";
    char dst8[10] = "ignore";
    const char *src3 = "";

    size_t ret_std_d = strlcat(dst7, src3, sizeof(dst7));
    size_t ret_ft_d = ft_strlcat(dst8, src3, sizeof(dst8));

    ASSERT_STR_EQ(dst7, dst8, "strlcat should keep dst unchanged if src empty");
    TEST("strlcat should return strlen(dst) if src is empty", ret_std_d == ret_ft_d);

    //TEST 5: dst vazia, espaço suficiente
    char dst1e[20] = "";
    char dst2e[20] = "";
    const char *src4 = "CopyMe";

    size_t ret_std_e = strlcat(dst1e, src4, sizeof(dst1e));
    size_t ret_ft_e = ft_strlcat(dst2e, src4, sizeof(dst2e));

    ASSERT_STR_EQ(dst1e, dst2e, "strlcat should copy all if dst is empty and buffer is big");
    TEST("strlcat return value should be strlen(src)", ret_std_e == ret_ft_e);

    // TEST 6: buffer exatamente do tamanho necessário
    char dst9[11] = "12345";
    char dst10[11] = "12345";
    const char *src5 = "6789";

    size_t ret_std_f = strlcat(dst9, src5, sizeof(dst9)); // buffer 11 bytes (5+4+1)
    size_t ret_ft_f = ft_strlcat(dst10, src5, sizeof(dst10));

    ASSERT_STR_EQ(dst9, dst10, "strlcat with exact buffer size");
    TEST("strlcat returns total length (dst + src)", ret_std_f == ret_ft_f);

    // TEST 7: buffer menor que strlen(dst)
    char dst11[5] = "1234"; // no room to concat
    char dst12[5] = "1234";
    const char *src6 = "abc";

    size_t ret_std_g = strlcat(dst11, src6, sizeof(dst11));
    size_t ret_ft_g = ft_strlcat(dst12, src6, sizeof(dst12));

    ASSERT_STR_EQ(dst11, dst12, "strlcat does not modify dst if size < strlen(dst)");
    TEST("strlcat returns size + strlen(src) if size < strlen(dst)", ret_std_g == ret_ft_g);

    return (fail);
}