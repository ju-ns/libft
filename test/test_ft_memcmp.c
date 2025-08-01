/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 01:34:49 by marvin            #+#    #+#             */
/*   Updated: 2025/08/01 01:34:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

#define TEST(description, condition) do { \
    if(!(condition)) { \
        printf("Test failed: %s\n", description); \
        fail = 1; \
    } \
} while(0)

int main (){
    int fail = 0;

    //TEST 1: Strings iguais
    char str1[] = "HelloWorld";
    char str2[] = "HelloWorld";
    int ret_std = memcmp(str1, str2, 10);
    int ret_ft = ft_memcmp(str1, str2, 10);
    TEST("memcmp with identical strings should return 0", ret_std == 0 && ret_ft == 0);

    //TEST 2: Diferença no meio
     char str3[] = "HelloWorld";
    char str4[] = "HellxWorld";
    ret_std = memcmp(str3, str4, 10);
    ret_ft = ft_memcmp(str3, str4, 10);
    TEST("memcmp with difference in middle", 
        (ret_std < 0 && ret_ft < 0) || (ret_std > 0 && ret_ft > 0));
    
    // TEST 3: Diferença no último byte
    char str5[] = "HelloWorld";
    char str6[] = "HelloWorlc";
    ret_std = memcmp(str5, str6, 10);
    ret_ft = ft_memcmp(str5, str6, 10);
    TEST("memcmp with difference at end", 
        (ret_std < 0 && ret_ft < 0) || (ret_std > 0 && ret_ft > 0));
    
    // TEST 4: Comparar 0 bytes (deve retornar 0)
    char str7[] = "ABC";
    char str8[] = "XYZ";
    ret_std = memcmp(str7, str8, 0);
    ret_ft = ft_memcmp(str7, str8, 0);
    TEST("memcmp with 0 bytes to compare", ret_std == 0 && ret_ft == 0);

    // TEST 5: Diferentes no primeiro byte
    char str9[] = "aBC";
    char str10[] = "zBC";
    ret_std = memcmp(str9, str10, 3);
    ret_ft = ft_memcmp(str9, str10, 3);
    TEST("memcmp with difference in first byte", 
        (ret_std < 0 && ret_ft < 0) || (ret_std > 0 && ret_ft > 0));
    return (fail);

}