/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:01:03 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/08 13:14:17 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:01:03 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/05 15:45:00 by jnogueir         ###   ########.fr       */
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

int reset_pipe(int pipefd[2], char *buf)
{
	memset(buf, 0, 100);
	if (pipefd[0] >= 0) close(pipefd[0]);
	if (pipefd[1] >= 0) close(pipefd[1]);
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (0);
}

int main(void)
{
	int fail = 0;
	int pipefd[2] = {-1, -1};
	char buf[100] = {0};
	ssize_t read_bytes;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}

	// TESTE 1: String comum
	memset(buf, 0, sizeof(buf));
	ft_putstr_fd("Hello!", pipefd[1]);
	close(pipefd[1]);
	read_bytes = read(pipefd[0], buf, strlen("Hello!"));
	TEST("ft_putstr_fd deve escrever 'Hello!'", read_bytes == (ssize_t)strlen("Hello!") && strcmp(buf, "Hello!") == 0);

	// TESTE 2: String vazia
	if (reset_pipe(pipefd, buf)) return (1);
	ft_putstr_fd("", pipefd[1]);
	close(pipefd[1]);
	read_bytes = read(pipefd[0], buf, 10);
	TEST("ft_putstr_fd com string vazia deve escrever 0 bytes", read_bytes == 0);

	// TESTE 3: String com espaços e pontuação
	if (reset_pipe(pipefd, buf)) return (1);
	ft_putstr_fd(" 42, SP!", pipefd[1]);
	close(pipefd[1]);
	read_bytes = read(pipefd[0], buf, strlen(" 42, SP!"));
	TEST("ft_putstr_fd com espaços e pontuação", read_bytes == (ssize_t)strlen(" 42, SP!") && strcmp(buf, " 42, SP!") == 0);

	// TESTE 4: String com caracteres especiais
	if (reset_pipe(pipefd, buf)) return (1);
	ft_putstr_fd("\tLine\n", pipefd[1]);
	close(pipefd[1]);
	read_bytes = read(pipefd[0], buf, strlen("\tLine\n"));
	TEST("ft_putstr_fd com \\t e \\n", read_bytes == (ssize_t)strlen("\tLine\n") && strcmp(buf, "\tLine\n") == 0);

	// TESTE 5: String longa
	if (reset_pipe(pipefd, buf)) return (1);
	char big_str[101];
	memset(big_str, 'A', 100);
	big_str[100] = '\0';
	ft_putstr_fd(big_str, pipefd[1]);
	close(pipefd[1]);
	read_bytes = read(pipefd[0], buf, 100);
	TEST("ft_putstr_fd com string de 100 'A's", read_bytes == 100 && strncmp(buf, big_str, 100) == 0);

	// Limpeza final
	if (pipefd[0] >= 0) close(pipefd[0]);

	return (fail);
}
