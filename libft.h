/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:49:06 by jnogueir          #+#    #+#             */
/*   Updated: 2025/07/25 11:07:19 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#if defined(__x86_64__) || defined(__aarch64__)
	typedef unsigned long size_t;
#else
	typedef unsigned int size_t;
#endif

//vericação de caracteres
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_tolower(int c);
int	ft_touper(int c);

//funções de memória
void	ft_bzero(void *s, size_t n);


#endif