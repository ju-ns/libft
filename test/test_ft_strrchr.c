/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:52:50 by marvin            #+#    #+#             */
/*   Updated: 2025/08/05 14:53:28 by jnogueir         ###   ########.fr       */
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

    //TEST 2: caractere não existe retorna NULL
    const char *str1 = "banana";
    char *ret_std1 = strrchr(str1, 'x');
    char *ret_ft1 = ft_strrchr(str1, 'x');

    TEST("ft_strrchr should return NULL", ret_std1 == ret_ft1);

    //TEST 3: retorna \0
    const char *str2 = "banana";
    char *ret_std2 = strrchr(str2, '\0');
    char *ret_ft2 = ft_strrchr(str2, '\0');

    TEST("ft_strrchr should return pointer to the last occurrence of '\0'", ret_std2 == ret_ft2);

    //TEST 4: string vazia caso não seja \0 como parametro retorna NULL
    const char *str3 = "";
    char *ret_std3 = strrchr(str3, 'a');
    char *ret_ft3 = ft_strrchr(str3, 'a');

    TEST("ft_strrchr should return NULL", ret_std3 == ret_ft3);

    //TEST 5: string vazia parametro \0 deve retornar \0 na primeira posição

    const char *str4 = "";
    char *ret_std4 = strrchr(str4, '\0');
    char *ret_ft4 = ft_strrchr(str4, '\0');

    TEST("ft_strrchr should return '\0'", ret_std4 == ret_ft4);

    //TEST 6: caractere no inicio da string

    const char *str5 = "abc";
    char *ret_std5 = strrchr(str5, 'a');
    char *ret_ft5 = ft_strrchr(str5, 'a');

    TEST("ft_strrchr should return 'a'", ret_std5 == ret_ft5);

    //TEST 7: string com espaços e acentos

    const char *str6 = "42 libft 0a A][[]]";
    char *ret_std6 = strrchr(str6, 'f');
    char *ret_ft6 = ft_strrchr(str6, 'f');

    TEST("ft_strrchr should return 'f'", ret_std6 == ret_ft6);

    // TEST 8: caractere único no meio da string
    const char *str7 = "hello";
    char *ret_std7 = strrchr(str7, 'l');
    char *ret_ft7 = ft_strrchr(str7, 'l');
    TEST("ft_strrchr should return last 'l' in 'hello'", ret_std7 == ret_ft7);

    // TEST 9: caractere símbolo especial
    const char *str8 = "[]][[";
    char *ret_std8 = strrchr(str8, '[');
    char *ret_ft8 = ft_strrchr(str8, '[');
    TEST("ft_strrchr should return last '[' in '[]][['", ret_std8 == ret_ft8);

    // TEST 10: string com um caractere, buscado presente
    const char *str9 = "a";
    char *ret_std9 = strrchr(str9, 'a');
    char *ret_ft9 = ft_strrchr(str9, 'a');
    TEST("ft_strrchr single char string with matching char", ret_std9 == ret_ft9);

    // TEST 11: string com um caractere, buscado ausente
    const char *str10 = "a";
    char *ret_std10 = strrchr(str10, 'b');
    char *ret_ft10 = ft_strrchr(str10, 'b');
    TEST("ft_strrchr single char string with non-matching char", ret_std10 == ret_ft10);

    // TEST 12: busca por '\0' em string longa
    const char *str11 = "long string test\0hidden";
    char *ret_std11 = strrchr(str11, '\0');
    char *ret_ft11 = ft_strrchr(str11, '\0');
    TEST("ft_strrchr should return pointer to terminator '\\0' in long string", ret_std11 == ret_ft11);

    return (fail);
}