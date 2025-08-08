/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:50:46 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 13:37:47 by jnogueir         ###   ########.fr       */
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

int main ()
{
    int fail = 0;
    //TEST 1: caractere existente no meio
    const char *str = "libft42";
    char c = 'f';
    
    char *ret_std = strchr(str, c);
    char *ret_ft = ft_strchr(str, c); 

    TEST("ft_strchr should return a pointer to character found", ret_std == ret_ft);

    //TEST 2: caractere no inicio da string 
    const char *str1 = "libft42";
    char *ret_std2 = strchr(str1, 'l');
    char *ret_ft2 = ft_strchr(str1, 'l');
    
    TEST("ft_strchr should find the caracter at the beginning", ret_std2 == ret_ft2);

    //TEST 3: caractere não existe na string
    const char *str2 = "libft42";
    char *ret_std3 = strchr(str2, 'x');
    char *ret_ft3 = ft_strchr(str2, 'x');

    TEST("ft_strchr should return NULL if the character doesn't exist", ret_std3 == ret_ft3);

    //TEST 4: Search \0
    const char *str3 = "libft42";
    char *ret_std4 = strchr(str3, '\0');
    char *ret_ft4 = ft_strchr(str3, '\0');

    TEST("ft_strchr should return a pointer for the null terminator", ret_std4 == ret_ft4);

    //TEST 5: Empty string with search for \0
    const char *str4 = "";
    char *ret_std5 = strchr(str4, '\0');
    char *ret_ft5 = ft_strchr(str4, '\0');

    TEST("ft_strchr should return a pointer to \\0 in an empty string", ret_std5 == ret_ft5);

     // TEST 6: string com caracteres repetidos (retorna a primeira ocorrência)
    const char *str5 = "aabcdee";
    char *ret_std6 = strchr(str5, 'e');
    char *ret_ft6 = ft_strchr(str5, 'e');
    TEST("ft_strchr should return pointer to first occurrence of 'e'", ret_std6 == ret_ft6);

    // TEST 7: busca por caractere negativo
    const char *str6 = "abc";
    char *ret_std7 = strchr(str6, -1);
    char *ret_ft7 = ft_strchr(str6, -1);
    TEST("ft_strchr should return NULL for negative char not matching", ret_std7 == ret_ft7);

    // TEST 8: busca por valor acima de 127 (255)
    const char *str7 = "abc";
    char *ret_std8 = strchr(str7, 255);
    char *ret_ft8 = ft_strchr(str7, 255);
    TEST("ft_strchr should return NULL for char 255", ret_std8 == ret_ft8);

    // TEST 9: caractere no final da string
    const char *str8 = "12345x";
    char *ret_std9 = strchr(str8, 'x');
    char *ret_ft9 = ft_strchr(str8, 'x');
    TEST("ft_strchr should find character at the end", ret_std9 == ret_ft9);

    // TEST 10: string com \\0 no meio (caractere após não deve ser lido)
    const char str9[] = {'a', 'b', '\0', 'c', '\0'};
    char *ret_std10 = strchr(str9, 'c');
    char *ret_ft10 = ft_strchr(str9, 'c');
    TEST("ft_strchr should not find character after internal \\0", ret_std10 == ret_ft10);
    
    return (fail);
}