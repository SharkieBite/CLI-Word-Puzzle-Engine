playWords: main.c words.c playWords.c playWords.h
	gcc -o playWords main.c words.c playWords.c
playtest: main.c words.c playWords.c playWords.h
	gcc --coverage -o playtest main.c words.c playWords.c