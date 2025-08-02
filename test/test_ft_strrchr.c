/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:52:50 by marvin            #+#    #+#             */
/*   Updated: 2025/08/02 18:52:50 by marvin           ###   ########.fr       */
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

    //TEST 1: caractere aparace mais de uma vez - deve retornar o ultimo
    const char *str = "banana";
    char *ret_std = strrchr(str, 'a');
    char *ret_ft = ft_strrchr(str, 'a');

    TEST("ft_strrchr should return pointer to the last occurrence of 'a'", ret_std == ret_ft);

    return (fail);
}