/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:47:20 by marvin            #+#    #+#             */
/*   Updated: 2025/08/03 19:47:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>


#define TEST(description, condition) do { \
	if (!(condition)) { \
		printf("Test failed: %s\n", description); \
		fail = 1; \
	} \
} while (0)

int main ()
{
    int fail = 0;
    //TEST 1: mesmo comportamento do atoi 
    const char *s1 = "1234";
    int sdt_st = atoi(s1);
    int sdt_ft = ft_atoi(s1);

    TEST("Should return same result of sdt_st", sdt_st == sdt_ft);

    return (fail);

}