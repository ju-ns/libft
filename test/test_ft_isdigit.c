/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:24:00 by jnogueir          #+#    #+#             */
/*   Updated: 2025/07/25 10:34:40 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main (void)
{
	int fail = 0;
	if (ft_isdigit('5') != 1)
	{
		printf("ft_isdigit('5') -> %d [FAIL]\n", ft_isdigit('5'));
		fail = 1;
	}
	if (ft_isdigit('a') != 0)
	{
		printf("ft_isdigit('a') -> %d [FAIL]\n", ft_isdigit('a'));
		fail = 1;
	}
	return (fail);
}
