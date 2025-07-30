#include <stdio.h>
#include "libft.h"
#include <string.h>


#define TEST(description, condition) do {\
	if ((!condition)) { \
		printf("Test failed: %s\n ", description); \
		fail = 1; \
	}\
}while(0)

#define ASSERT_MEM_EQ(a, b, n, description) do { \
	if(memcmp((a), (b), (n) != 0)) {\
		printf("Test failed: %s\n ", description); \
		fail = 1; \
	}\
} while(0)

#define ASSERT_TRUE(condition, description) do { \
	if(!(condition)) { \
		printf("Test failed: %s\n", description); \
		fail = 1; \
	} \
} while (0)

int main (){
	int fail = 0;
	unsigned char buffer1[10];
	unsigned char buffer2[10];

	//TEST1 - Comportamento básico
	memset(buffer1, 'X', 4);
	ft_memset(buffer2, 'X', 4);
	ASSERT_MEM_EQ(buffer1, buffer2, 10, "ft_memset should fill with 'X' correctly");

	//TEST2 - Len parcial
	memset(buffer1, 'B', 5);
	ft_memset(buffer2, 'B', 5);
	ASSERT_MEM_EQ(buffer1, buffer2, 5, "ft_memset should fill 5 bytes with 'B'");

	//TEST3 - len = 0 (nada muda)
	memset(buffer1, 'C', 10);
	memset(buffer2, 'C', 10);

	size_t len = 0;
	ft_memset(buffer1, 'X', len);
	memset(buffer2, 'X', len);
	ASSERT_MEM_EQ(buffer1, buffer2, len, "ft_memset with len = 0 should not change");

	//TEST4 - informa o ponto de partida
	memset(buffer1 + 2, 'X', 2);
	ft_memset(buffer2 + 2, 'X', 2);
	ASSERT_MEM_EQ(buffer1 + 2, buffer2 + 2, 2, "ft_memset must fill from the index two");

	//TEST5 - preenchimento parcial (primeiros bytes)
	memset(buffer1, 'A', 10);
	ft_memset(buffer2, 'A', 10);

	memset(buffer1, 'B', 3);
	ft_memset(buffer2, 'B', 3);

	ASSERT_MEM_EQ(buffer1, buffer2, 10, "ft_memset must overwrite only the first 3 bytes");

	//TEST6 - ponteiro NULL com n > 0
	char *ptr = NULL;
	void *ret_null = ft_memset(ptr, 'X', 0);

	ASSERT_TRUE(ret_null == ptr, "ft_memset(NULL, 'X', 0) must return the original pointer");

	//TEST7 - retorno da função 
	char data[5];
	void *ret = ft_memset(data, 'Z', 5);

	ASSERT_TRUE(ret == data, "ft_memset must return the original pointer");


	return (fail);
}