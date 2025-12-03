playWords: words.c checkletter.c checkWord.c chooseWord.c
	gcc -o playWords words.c checkletter.c checkWord.c chooseWord.c
playtest: words.c checkletter.c checkWord.c chooseWord.c
	gcc -o playtest --coverage words.c checkletter.c checkWord.c chooseWord.c
checkletter: checkletter.c
	gcc -o checkletter checkletter.c
checkword: checkWord.c
	gcc -o checkword checkWord.c
chooseword: chooseWord.c
	gcc -o chooseword chooseWord.c
