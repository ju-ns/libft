/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:46:34 by jnogueir          #+#    #+#             */
/*   Updated: 2025/08/08 13:13:26 by jnogueir         ###   ########.fr       */
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
	if (!content)
		return NULL;
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
void *f_return_null(void *content)
 {
	(void)content;
	return NULL;
}
int main(void)
{
	int fail = 0;

	// TEST 1: lista normal mapeada corretamente
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

	// TEST 2: lista vazia (NULL)
	t_list *empty = NULL;
	t_list *mapped_empty = ft_lstmap(empty, to_upper_copy, del_content);
	TEST("mapeamento de lista NULL retorna NULL", mapped_empty == NULL);

	// TEST 3: função f retorna NULL (simula falha de alocação)
	t_list *lst_fail = ft_lstnew(strdup("fail"));
	t_list *res_fail = ft_lstmap(lst_fail, f_return_null, del_content);
	TEST("ft_lstmap deve retornar NULL se f retorna NULL", res_fail == NULL);
	ft_lstclear(&lst_fail, free);
	ft_lstclear(&res_fail, del_content); // seguro limpar NULL

	// TEST 4: função del NULL (não recomendado, mas vamos testar)
	t_list *lst_del_null = ft_lstnew(strdup("delnull"));
	t_list *res_del_null = ft_lstmap(lst_del_null, to_upper_copy, NULL);
	TEST("ft_lstmap funciona mesmo se del é NULL", res_del_null != NULL);
	ft_lstclear(&lst_del_null, NULL);
	ft_lstclear(&res_del_null, NULL);

	// TEST 5: conteúdo NULL em original (deve mapear corretamente)
	t_list *lst_null_content = ft_lstnew(NULL);
	t_list *mapped_null_content = ft_lstmap(lst_null_content, to_upper_copy, del_content);
	TEST("mapeamento de nó com content NULL retorna NULL ou nó vazio", 
		(mapped_null_content == NULL) || (mapped_null_content->content == NULL));
	ft_lstclear(&lst_null_content, free);
	ft_lstclear(&mapped_null_content, del_content);

	// TEST 6: original com 1 nó
	t_list *single_node = ft_lstnew(strdup("single"));
	t_list *mapped_single = ft_lstmap(single_node, to_upper_copy, del_content);
	TEST("mapeamento com 1 nó altera conteúdo", strcmp(mapped_single->content, "SINGLE") == 0);
	ft_lstclear(&single_node, free);
	ft_lstclear(&mapped_single, del_content);

	return fail;
}