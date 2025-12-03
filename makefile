playWords: words.c playWords.c
	gcc -o playWords words.c playWords.c
playtest: playWords.c
	gcc -o playtest --coverage playWords.c
checkletter: checkletter.c
	gcc -o checkletter checkletter.c
checkrepeat: checkRepeat.c
	gcc -o checkrepeat checkRepeat.c
checkword: checkWord.c
	gcc -o checkword checkWord.c
chooseword: chooseWord.c
	gcc -o chooseword chooseWord.c
