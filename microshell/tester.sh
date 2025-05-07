# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/20 02:26:11 by jcluzet           #+#    #+#              #
#    Updated: 2025/05/07 16:01:42 by aelaaser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE='source.c'
ASSIGN='microshell.c'

index=0

if [ -e traceback ]
then
    rm traceback
fi

{
	gcc -Wall -Wextra -Werror $FILE
} &>/dev/null

touch sourcexam
touch finalexam
sh test.sh &> sourcexam       #TESTING VRAI
{
rm a.out
} &>/dev/null
{
gcc -Wall -Wextra -Werror $ASSIGN
}  &>.dev
sh test.sh &> finalexam        #TESTING STUD
# {
# }  &>/dev/null



DIFF=$(diff sourcexam finalexam)
if [ "$DIFF" != "" ]
then
        echo "----------------8<-------------[ START TEST " >> traceback
		if [ -e a.out ]
		then
        printf "        💻 ALL TESTS: \n\n$(cat ./test.sh)\n" >> traceback
        printf "\n\n        🔎 YOUR OUTPUT:\n" >> traceback
        cat finalexam >> traceback
        printf "\n\n        🗝 EXPECTED OUTPUT:\n" >> traceback
		cat sourcexam >> traceback
		else
		printf "        🔎 YOUR OUTPUT:\n" >> traceback
        # cat finalexam >> traceback
        printf "\n";
        echo "$(cat .dev)" >> traceback
        rm .dev
		printf "\n        ❌ COMPILATION ERROR\n" >> traceback
		fi
        echo "----------------8<------------- END TEST ]" >> traceback
		index=$((index+1))
fi
# exit


rm finalexam
{
rm sourcexam
rm a.out
rm .dev
} &>/dev/null


#mv .system/tester.sh .system/grading/tester.sh


if [ $index -eq 0 ]
then
	echo "OK"
else
	echo "fail"
fi
