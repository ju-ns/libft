#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

TEST_DIR="./test"
LIBFT_DIR=".."

cd "$LIBFT_DIR" || exit
make re > /dev/null
cd "$TEST_DIR" || exit

if [ ! -f "../libft.a"]; then
	echo -e "{RED}[ERRO] libft.a not found!${NC}"
fi

echo -e "${YELLOW}=== Starting unit tests ===${NC}"

for test_file in test_*.c; do
	name=$(basename "$test_file" .c)
	exe="${name}.out"
	#compile the test
	cc -Wall -Wextra -Werror -I.. "$test_file" ../libft.a -o "$exe"
	if [ $? -ne 0]; then
		echo -e "${RED}[ERRO] fail to compile $name${NC}"
		continue
	fi
	#run the test
	./"$exe"
	if [ $? -eq 0]; then
		echo -e "${GREEN}[PASS] $name${NC}"
	else
		echo -e "${RED}[FAIL] &name${NC}"
	fi

	rm -f "$exe"
done
echo -e "${YELLOW}=== Tests completed ===${NC}"



