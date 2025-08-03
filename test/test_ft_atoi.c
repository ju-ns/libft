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
    //TEST 1: numero positivo simples 
    const char *s1 = "1234";
    int sdt_st = atoi(s1);
    int sdt_ft = ft_atoi(s1);

    TEST("basic positive number", sdt_st == sdt_ft);

    //TEST 2: com espaços antes 
    const char *str2 = "   \t\n  123";
    int std2 = atoi(str2);
    int ft2  = ft_atoi(str2);
    TEST("spaces before number", std2 == ft2);

    //TEST 3: numero negativo
    const char *str3 = "   -456";
    int std3 = atoi(str3);
    int ft3  = ft_atoi(str3);
    TEST("negative number with leading spaces", std3 == ft3);

    //TEST 4: numero com sinal positivo explícito
    const char *str4 = "+789";
    int std4 = atoi(str4);
    int ft4  = ft_atoi(str4);
    TEST("explicit positive sign", std4 == ft4);

    //TEST 5: string com letras depois 
    const char *str5 = "42abc";
    int std5 = atoi(str5);
    int ft5  = ft_atoi(str5);
    TEST("number with trailing characters", std5 == ft5);

    //TEST 6: string que começa com letra 
    const char *str6 = "abc123";
    int std6 = atoi(str6);
    int ft6  = ft_atoi(str6);
    TEST("string with no leading number", std6 == ft6);
    return (fail);

}