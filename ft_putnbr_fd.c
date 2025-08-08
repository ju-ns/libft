/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:29:25 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/05 15:58:14 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

//testando v1
void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	write(fd, str, ft_strlen(str));
	free(str);
}

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	c;

// 	if (n == -2147483648)
// 	{
// 		write(fd, "-2147483648", 11);
// 		return ;
// 	}
// 	if (n < 0)
// 	{
// 		write(fd, "-", 1);
// 		n = -n;
// 	}
// 	if (n >= 10)
// 		ft_putnbr_fd(n / 10, fd);
// 	c = (n % 10) + '0';
// 	write(fd, &c, 1);
// }
