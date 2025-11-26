play: playWordle.c
	gcc -o play playWordle.c
playtest: playWordle.c
	gcc -o playtest --coverage playWordle.c
