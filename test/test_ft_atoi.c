/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:03:26 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/05 13:04:27 by jnogueir         ###   ########.fr       */
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
    
    // TEST 7: string vazia
    const char *str7 = "";
    TEST("empty string", ft_atoi(str7) == atoi(str7));

    // TEST 8: apenas espaços
    const char *str8 = "    \t\n";
    TEST("only whitespace", ft_atoi(str8) == atoi(str8));

    // TEST 9: sinais consecutivos inválidos
    const char *str9 = "--123";
    TEST("double negative signs", ft_atoi(str9) == atoi(str9));
    const char *str10 = "+-123";
    TEST("mixed signs", ft_atoi(str10) == atoi(str10));

    // TEST 10: número zero
    const char *str11 = "0";
    TEST("zero number", ft_atoi(str11) == atoi(str11));
    const char *str12 = "-0";
    TEST("negative zero", ft_atoi(str12) == atoi(str12));

    // TEST 11: zeros à esquerda
    const char *str13 = "0000123";
    TEST("leading zeros positive", ft_atoi(str13) == atoi(str13));
    const char *str14 = "-0000123";
    TEST("leading zeros negative", ft_atoi(str14) == atoi(str14));

    // TEST 12: só sinal sem número
    const char *str15 = "+";
    TEST("only plus sign", ft_atoi(str15) == atoi(str15));
    const char *str16 = "-";
    TEST("only minus sign", ft_atoi(str16) == atoi(str16));

    return (fail);

}