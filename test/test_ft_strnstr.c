/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:44:40 by marvin            #+#    #+#             */
/*   Updated: 2025/08/03 14:44:40 by marvin           ###   ########.fr       */
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

static char *my_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (!*needle)
		return (char *)haystack;

	for (i = 0; haystack[i] && i < len; i++)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
	}
	return NULL;
}


int main()
{
    int fail = 0;

    //TEST 1: ft_strnstr precisa manter o mesmo comportamento que a strnstr
    const char *haystack = "42sp";
    const char *needle = "sp";
    
    char *std_sd = my_strnstr(haystack,needle,4);
    char *std_ft = ft_strnstr(haystack,needle,4);

    TEST("ft_strnstr should match behavior of my_strnstr", std_sd == std_ft);

    //TEST 2: needle esta no começo
    const char *h2 = "banana";
    const char *n2 = "ban";
    char *ref2 = my_strnstr(h2, n2, 6);
    char *res2 = ft_strnstr(h2, n2, 6);
    TEST("needle at beginning of haystack", ref2 == res2);

    //TEST 3: needle no meio mas depois que len
    const char *h3 = "hello42sp";
    const char *n3 = "42";
    char *ref3 = my_strnstr(h3, n3, 5);  // só vê até "hello"
    char *res3 = ft_strnstr(h3, n3, 5);
    TEST("needle after len — should return NULL", ref3 == res3);

    //TEST 4: needle vazia 
    const char *h4 = "something";
    const char *n4 = "";
    char *ref4 = my_strnstr(h4, n4, 5);
    char *res4 = ft_strnstr(h4, n4, 5);
    TEST("empty needle — should return haystack", ref4 == res4);

    //TEST 5: needle maior que haystack
    const char *h5 = "abc";
    const char *n5 = "abcdef";
    char *ref5 = my_strnstr(h5, n5, 6);
    char *res5 = ft_strnstr(h5, n5, 6);
    TEST("needle longer than haystack — should return NULL", ref5 == res5);

    //TEST 6: len = 0
    const char *h6 = "notempty";
    const char *n6 = "not";
    char *ref6 = my_strnstr(h6, n6, 0);
    char *res6 = ft_strnstr(h6, n6, 0);
    TEST("len = 0 — should return NULL unless needle is empty", ref6 == res6);

    return (fail);

}