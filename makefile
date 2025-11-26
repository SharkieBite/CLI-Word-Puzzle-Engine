play: playWords.c
	gcc -o play playWords.c
playtest: playWords.c
	gcc -o playtest --coverage playWords.c
