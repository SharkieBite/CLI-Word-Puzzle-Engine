#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_GUESSES 6        
#define MAX_WORD_LENGTH 6    

int guessCount = 0;


bool isNewGuess(const char *word, char oldGuesses[][MAX_WORD_LENGTH], int guessCount) {
    for (int i = 0; i < guessCount; i++) {
        if (strcmp(oldGuesses[i], word) == 0) {
            printf("already guessed\n");
            return false; 
        }
    }
    return true; 
}
