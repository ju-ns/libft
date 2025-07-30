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

	return (fail);
}