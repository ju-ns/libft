/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:00:20 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/05 13:25:49 by jnogueir         ###   ########.fr       */
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
	char buf[100] = {0};

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}

	// TESTE 1: Escreve string + \n
	ft_putendl_fd("Hello!", pipefd[1]);
	read(pipefd[0], buf, 7); // lê 7 bytes (6 da string + 1 do \n)
	TEST("ft_putendl_fd deve escrever 'Hello!\\n'", strcmp(buf, "Hello!\n") == 0);

	// TESTE 2: String vazia (deve escrever só \n)
	memset(buf, 0, sizeof(buf));
	ft_putendl_fd("", pipefd[1]);
	read(pipefd[0], buf, 1);
	TEST("ft_putendl_fd com string vazia escreve só '\\n'", strcmp(buf, "\n") == 0);

	// TESTE 3: String com \n interno
	memset(buf, 0, sizeof(buf));
	ft_putendl_fd("Linha1\nLinha2", pipefd[1]);
	read(pipefd[0], buf, strlen("Linha1\nLinha2") + 1);
	TEST("ft_putendl_fd escreve string com \\n interno + \\n final", strcmp(buf, "Linha1\nLinha2\n") == 0);

	// TESTE 4: múltiplas chamadas
	memset(buf, 0, sizeof(buf));
	ft_putendl_fd("X", pipefd[1]);
	ft_putendl_fd("Y", pipefd[1]);
	read(pipefd[0], buf, 4); // "X\nY\n"
	TEST("ft_putendl_fd múltiplas chamadas", strcmp(buf, "X\nY\n") == 0);

	close(pipefd[0]);
	close(pipefd[1]);


	return (fail);
}