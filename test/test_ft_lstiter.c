/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:45:49 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/08 12:12:32 by jnogueir         ###   ########.fr       */
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

// função que modifica o conteúdo para um inteiro (incrementa valor)
void increment_int(void *content) {
	if (!content) return;
	int *p = (int *)content;
	(*p)++;
}

// função que não modifica o conteúdo
void no_op(void *content) {
	(void)content;
}

int main(void)
{
	int fail = 0;

	// TEST 1: lista normal, converte strings para maiúsculas
	t_list *lst = ft_lstnew(strdup("hello"));
	ft_lstadd_back(&lst, ft_lstnew(strdup("world")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("libft")));

	ft_lstiter(lst, to_upper);

	TEST("primeiro nó deve ser 'HELLO'", strcmp((char *)lst->content, "HELLO") == 0);
	TEST("último nó deve ser 'LIBFT'", strcmp((char *)lst->next->next->content, "LIBFT") == 0);

	ft_lstclear(&lst, free);

	// TEST 2: lista com um elemento só
	t_list *single = ft_lstnew(strdup("single"));
	ft_lstiter(single, to_upper);
	TEST("único nó deve ser 'SINGLE'", strcmp((char *)single->content, "SINGLE") == 0);
	ft_lstclear(&single, free);

	// TEST 3: lista vazia (NULL)
	t_list *empty = NULL;
	ft_lstiter(empty, to_upper); // deve fazer nada e não crashar
	TEST("lista NULL não causa erro", 1);

	// TEST 4: função f é NULL (deve evitar crash)
	t_list *lst2 = ft_lstnew(strdup("abc"));
	ft_lstiter(lst2, NULL);
	TEST("função NULL não causa erro", 1);
	ft_lstclear(&lst2, free);

	// TEST 5: lista com conteúdo NULL
	t_list *null_content = ft_lstnew(NULL);
	ft_lstiter(null_content, to_upper); // deve lidar sem crash
	TEST("nó com content NULL não causa erro", 1);
	ft_lstclear(&null_content, free);

	// TEST 6: função que não altera conteúdo
	t_list *lst3 = ft_lstnew(strdup("nochange"));
	ft_lstadd_back(&lst3, ft_lstnew(strdup("stillnochange")));
	ft_lstiter(lst3, no_op);
	TEST("conteúdo permanece 'nochange'", strcmp((char *)lst3->content, "nochange") == 0);
	TEST("segundo nó permanece 'stillnochange'", strcmp((char *)lst3->next->content, "stillnochange") == 0);
	ft_lstclear(&lst3, free);

	// TEST 7: lista com conteúdo de inteiros
	int *i1 = malloc(sizeof(int));
	int *i2 = malloc(sizeof(int));
	*i1 = 10;
	*i2 = 20;
	t_list *int_list = ft_lstnew(i1);
	ft_lstadd_back(&int_list, ft_lstnew(i2));
	ft_lstiter(int_list, increment_int);
	TEST("primeiro int incrementado para 11", * (int *)int_list->content == 11);
	TEST("segundo int incrementado para 21", * (int *)int_list->next->content == 21);
	ft_lstclear(&int_list, free);

	return fail;

}