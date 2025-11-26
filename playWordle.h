#include <stdbool.h>

char *chooseWord(int number);
bool isNewGuess(const char *word, char oldGuesses[][MAX_WORD_LENGTH], int guessCount);
void checkFullWordPlacement(const char *correctWord, const char *userGuess);
bool checkCorrectLengthconst (char *correctWord, const char *userGuess);