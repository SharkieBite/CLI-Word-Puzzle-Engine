#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_GUESSES 6        
#define MAX_WORD_LENGTH 6    

void help(){

	puts("Checks if the current guess is a repeat of any previous guesses");\
	puts("Usage: takes the current guess and a 2D array holding all the previous guesses and checks none of them are the same");
}

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

int main(int argc, char *input[]){
    if (argc >= 2 && strcmp(input[1], "--help") == 0) {
        help();
        return 0;
    }
}
