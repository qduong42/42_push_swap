#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NOCLR='\033[0m'
YELLOW='\e[93m'

checkAnswer() {
	if diff <(printf "$1") tmp.txt > /dev/null;then
		printf $"${GREEN}OK\n${NOCLR}"
	else printf $"${RED}KO\n${NOCLR}"
	fi
}


if [ "$#" -ne 1 ]; then
    printf "Please provide path to user executable.\n"
	exit
fi

printf "\n${GREEN}============= ${YELLOW}Error detection${GREEN} ===========\n${NOCLR}"

printf "Too many <- expected: Error\n"
./$1 "4 2 2 1 1 2 3 3 4 2 2 1 1 2 3 3 4" | tee tmp.txt
checkAnswer $'Error\n'

printf "\nNot enough <- expected: Error\n"
./$1 "4 2 2 1 1 2 3 3 4 2 2 1 1 2 3" | tee tmp.txt
checkAnswer $'Error\n'

printf "\nImpossible <- expected: Error\n"
./$1 "4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4" | tee tmp.txt
checkAnswer $'Error\n'

printf "\nInvalid character <- expected: Error\n"
./$1 "4 2 2 1 1 A 3 3 4 2 2 1 1 2 3 3" | tee tmp.txt
checkAnswer $'Error\n'

printf "\nNumber too high <- expected: Error\n"
./$1 "4 2 2 1 1 5 3 3 4 2 2 1 1 2 3 3" | tee tmp.txt
checkAnswer $'Error\n'

printf "\nNumber too low <- expected: Error\n"
./$1 "4 2 2 1 1 0 3 3 4 2 2 1 1 2 3 3" | tee tmp.txt
checkAnswer $'Error\n'

printf "\nNumber 42 <- expected: Error\n"
./$1 "4 2 2 1 1 42 3 3 4 2 2 1 1 2 3 3" | tee tmp.txt
checkAnswer $'Error\n'

printf "\nToo many spaces <- expected: Error\n"
./$1 "4 2 2 1   1 2 3 3 4 2 2 1 1 2 3" | tee tmp.txt
checkAnswer $'Error\n'


printf "\n${GREEN}=============== ${YELLOW}Solving${GREEN} ==================\n${NOCLR}"


echo "From the Subject - 4 3 2 1 - 1 2 2 2 - 4 3 2 1 - 1 2 2 2"
echo "----------------------------------"
./$1 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | tee tmp.txt
checkAnswer $'1 2 3 4\n2 3 4 1\n3 4 1 2\n4 1 2 3\n'
printf "%s\n\n" "----------------------------------"

echo "Level 1 -    up   -   down  -   left  -  right"
echo "Level 1 - 4 2 2 1 - 1 2 3 3 - 4 2 2 1 - 1 2 3 3"
echo "----------------------------------"
./$1 "4 2 2 1 1 2 3 3 4 2 2 1 1 2 3 3" | tee tmp.txt
checkAnswer $'1 2 3 4\n2 1 4 3\n3 4 2 1\n4 3 1 2\n'
printf "%s\n\n" "----------------------------------"

printf "Level 2 -    up   -   down  -   left  - right"
echo "Level 2 - 3 2 2 1 - 2 2 1 3 - 4 2 1 3 - 1 2 2 2"
echo "----------------------------------"
./$1 "3 2 2 1 2 2 1 3 4 2 1 3 1 2 2 2" | tee tmp.txt
checkAnswer $'1 2 3 4\n3 4 1 2\n4 1 2 3\n2 3 4 1\n'
printf "%s\n\n" "----------------------------------"

echo "Level 3 -    up   -   down  -   left  -  right"
echo "Level 3 - 3 2 1 2 - 1 2 3 2 - 2 2 2 1 - 2 3 1 4"
echo "----------------------------------"
./$1 "3 2 1 2 1 2 3 2 2 2 2 1 2 3 1 4" | tee tmp.txt
checkAnswer $'2 1 4 3\n1 4 3 2\n3 2 1 4\n4 3 2 1\n'
printf "%s\n\n" "----------------------------------"

echo "Level 4 -    up   -   down  -   left  -  right"
echo "Level 4 - 2 2 3 1 - 3 2 1 2 - 3 1 2 3 - 1 3 3 2"
echo "----------------------------------"
./$1 "2 2 3 1 3 2 1 2 3 1 2 3 1 3 3 2" | tee tmp.txt
checkAnswer $'2 3 1 4\n4 1 3 2\n3 4 2 1\n1 2 4 3\n'
printf "%s\n\n" "----------------------------------"

echo "Level 5 -    up   -   down  -   left  -  right"
echo "Level 5 - 2 3 3 1 - 3 2 1 2 - 2 1 2 3 - 1 3 3 2"
echo "----------------------------------"
./$1 "2 3 3 1 3 2 1 2 2 1 2 3 1 3 3 2" | tee tmp.txt
checkAnswer $'3 1 2 4\n4 3 1 2\n2 4 3 1\n1 2 4 3\n'
printf "%s\n\n" "----------------------------------"

rm -f tmp.txt
printf "\n${GREEN}==============${YELLOW} Done${GREEN} ================\n${NOCLR}"

printf "${RED}KO${NOCLR}: Too many errors, you failed! Grade: ${RED}-42\n"
