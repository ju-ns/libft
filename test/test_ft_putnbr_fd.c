/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:01:28 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/05 14:46:58 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#define TEST(desc, cond) do { \
	if (!(cond)) { \
		printf("Test failed: %s\n", desc); \
		fail = 1; \
	} \
} while (0)

void reset_pipe(int pipefd[2], char *buf)
{
	memset(buf, 0, 100);
	if (pipefd[0] >= 0) close(pipefd[0]);
	if (pipefd[1] >= 0) close(pipefd[1]);
	if (pipe(pipefd) == -1) {
		perror("pipe");
		_exit(1);
	}
}

int main(void)
{
	int fail = 0;
	int pipefd[2] = {-1, -1};
	char buf[100] = {0};
	ssize_t read_bytes;

	if (pipe(pipefd) == -1) {
		perror("pipe");
		return 1;
	}

	// TESTE 1: número positivo
	memset(buf, 0, sizeof(buf));
	ft_putnbr_fd(123, pipefd[1]);
	read_bytes = read(pipefd[0], buf, sizeof(buf));
	TEST("ft_putnbr_fd deve escrever '123'", read_bytes == 3 && strcmp(buf, "123") == 0);

	// TESTE 2: número negativo
	reset_pipe(pipefd, buf);
	ft_putnbr_fd(-42, pipefd[1]);
	read_bytes = read(pipefd[0], buf, sizeof(buf));
	TEST("ft_putnbr_fd deve escrever '-42'", read_bytes == 3 && strcmp(buf, "-42") == 0);

	// TESTE 3: zero
	reset_pipe(pipefd, buf);
	ft_putnbr_fd(0, pipefd[1]);
	read_bytes = read(pipefd[0], buf, sizeof(buf));
	TEST("ft_putnbr_fd deve escrever '0'", read_bytes == 1 && strcmp(buf, "0") == 0);

	// TESTE 4: número negativo grande
	reset_pipe(pipefd, buf);
	ft_putnbr_fd(-123456, pipefd[1]);
	read_bytes = read(pipefd[0], buf, sizeof(buf));
	TEST("ft_putnbr_fd deve escrever '-123456'", read_bytes == 7 && strcmp(buf, "-123456") == 0);

	// TESTE 5: INT_MIN
	reset_pipe(pipefd, buf);
	ft_putnbr_fd(INT_MIN, pipefd[1]);
	read_bytes = read(pipefd[0], buf, sizeof(buf));
	TEST("ft_putnbr_fd deve escrever INT_MIN", read_bytes == 11 && strcmp(buf, "-2147483648") == 0);

	// TESTE 6: INT_MAX
	reset_pipe(pipefd, buf);
	ft_putnbr_fd(INT_MAX, pipefd[1]);
	read_bytes = read(pipefd[0], buf, sizeof(buf));
	TEST("ft_putnbr_fd deve escrever INT_MAX", read_bytes == 10 && strcmp(buf, "2147483647") == 0);

	// TESTE 7: múltiplas chamadas
	reset_pipe(pipefd, buf);
	ft_putnbr_fd(1, pipefd[1]);
	ft_putnbr_fd(2, pipefd[1]);
	ft_putnbr_fd(3, pipefd[1]);
	read_bytes = read(pipefd[0], buf, sizeof(buf));
	TEST("ft_putnbr_fd deve escrever '123'", read_bytes == 3 && strcmp(buf, "123") == 0);

	// limpeza
	close(pipefd[0]);
	close(pipefd[1]);

	return fail;
}

