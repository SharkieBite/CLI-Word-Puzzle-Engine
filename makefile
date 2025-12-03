playWords: main.c words.c words.h checkletter.c checkWord.c chooseWord.c
	gcc -o playWords main.c words.c checkletter.c checkWord.c chooseWord.c
playtest: main.c words.c words.h checkletter.c checkWord.c chooseWord.c
	gcc --coverage -o playtest main.c words.c checkletter.c checkWord.c chooseWord.c