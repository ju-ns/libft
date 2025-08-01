/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 02:07:26 by marvin            #+#    #+#             */
/*   Updated: 2025/08/01 02:07:26 by marvin           ###   ########.fr       */
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

int main() {
    int fail = 0;

    // TEST 2: String comum
    TEST("\"42SãoPaulo\" should return 10",
         ft_strlen("42SãoPaulo") == strlen("42SãoPaulo"));
    
    return (fail);
    
}