/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:14:43 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/05 12:15:45 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	size_t			s_len;
	unsigned int	i;
	char			*new_string;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	new_string = malloc(s_len + 1);
	i = 0;
	while (s[i])
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
