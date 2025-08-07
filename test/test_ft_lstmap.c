/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:08:15 by marvin            #+#    #+#             */
/*   Updated: 2025/08/07 10:08:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TEST(desc, cond) do { \
	if (!(cond)) { \
		printf("Test failed: %s\n", desc); \
		fail = 1; \
	} \
} while (0)

// transforma string em maiúsculas (copia nova)
void *to_upper_copy(void *content)
{
	char *str = (char *)content;
	char *copy = strdup(str);
	if (!copy)
		return NULL;
	for (int i = 0; copy[i]; i++)
		if (copy[i] >= 'a' && copy[i] <= 'z')
			copy[i] -= 32;
	return copy;
}

// função de liberação
void del_content(void *content)
{
	free(content);
}

int main(void)
{
	int fail = 0;

	t_list *original = ft_lstnew(strdup("one"));
	ft_lstadd_back(&original, ft_lstnew(strdup("two")));
	ft_lstadd_back(&original, ft_lstnew(strdup("three")));

	t_list *mapped = ft_lstmap(original, to_upper_copy, del_content);

	TEST("mapped lista deve conter 'ONE'", strcmp(mapped->content, "ONE") == 0);
	TEST("mapped lista deve conter 'TWO'", strcmp(mapped->next->content, "TWO") == 0);
	TEST("mapped lista deve conter 'THREE'", strcmp(mapped->next->next->content, "THREE") == 0);

	TEST("original lista permanece 'one'", strcmp(original->content, "one") == 0);

	// limpeza
	ft_lstclear(&original, free);
	ft_lstclear(&mapped, free);

	return fail;
}
