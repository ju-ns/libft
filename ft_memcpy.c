/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:48:18 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/05 11:52:03 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n){
	const char	*src_char;
	size_t		i;
	char		*dest_char;

	src_char = (const char *) src;
	dest_char = (char *) dest;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}