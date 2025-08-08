/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:05:14 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/05 12:07:39 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri( char *s, void(*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
    i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
