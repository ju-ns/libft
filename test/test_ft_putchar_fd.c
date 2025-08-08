/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:57:34 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/05 14:27:43 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define TEST(desc, cond) do { \
	if (!(cond)) { \
		printf("Test failed: %s\n", desc); \
		fail = 1; \
	} \
} while (0)

int main(void)
{
	int fail = 0;
	int pipefd[2];
	char buf[2] = {0};

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}

	// Teste 1: caractere 'A'
	ft_putchar_fd('A', pipefd[1]);
	read(pipefd[0], buf, 1); // lê 1 byte

	TEST("ft_putchar_fd deve escrever 'A'", buf[0] == 'A');

	// Teste 2: caractere '\n'
	ft_putchar_fd('\n', pipefd[1]);
	read(pipefd[0], buf + 1, 1);
	TEST("ft_putchar_fd deve escrever '\\n'", buf[1] == '\n');

	// Teste 3: múltiplos caracteres
	const char *chars = "xyz";
	for (int i = 0; i < 3; i++)
		ft_putchar_fd(chars[i], pipefd[1]);
	read(pipefd[0], buf + 2, 3);
	TEST("ft_putchar_fd deve escrever 'xyz'", memcmp(buf + 2, "xyz", 3) == 0);

	// Teste 4: fd inválido (espera-se que não escreva nada, mas também não cause crash)
	ssize_t res = 0;
	// Pode tentar capturar erro, mas normalmente write retorna -1 e errno é setado
	res = write(-1, "Z", 1);

	close(pipefd[0]);
	close(pipefd[1]);


	return (fail);
}