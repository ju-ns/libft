/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:06:07 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 10:06:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST(desc, cond) do { \
	if (!(cond)) { \
		printf("Test failed: %s\n", desc); \
		fail = 1; \
	} \
} while (0)

// função que modifica o conteúdo (tudo para maiúsculas)
void to_upper(void *content) {
	char *str = (char *)content;
	for (int i = 0; str[i]; i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
}

int main(void)
{
	int fail = 0;

	t_list *lst = ft_lstnew(strdup("hello"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("world")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("libft")));

	ft_lstiter(lst, to_upper);

	TEST("primeiro nó deve ser 'HELLO'", strcmp((char *)lst->content, "HELLO") == 0);
	TEST("último nó deve ser 'LIBFT'", strcmp((char *)lst->next->next->content, "LIBFT") == 0);

	// limpeza
	ft_lstclear(&lst, free);

	return fail;
}
