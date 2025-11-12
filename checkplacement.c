#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

void checkWordPlacement(const char *correctWord, const char *userGuess) {
    
    int guessLength = strlen(correctWord);
    
    printf("Guess:   %s\n", userGuess);
    printf("Result:  ");

    for (int i = 0; i < guessLength; i++) {
        if (userGuess[i] == correctWord[i]) {
            printf("G");
        } else {
            printf("-"); 
        }
    }
    printf("\n");
}

void checkFullWordPlacement(const char *correctWord, const char *userGuess) {
    
    int guessLength = strlen(correctWord);
    
    char checkedGuess[guessLength];
    int checkedPlacement[guessLength];
    
   // printf("Guess:   %s\n", userGuess);
   // printf("Result:  ");

    for (int i = 0; i < guessLength; i++) {
        if (userGuess[i] == correctWord[i]) {
            checkedGuess[i] = 'G';
            checkedPlacement[i] = 1;

        } else {
            checkedGuess[i] = 'W';
            checkedPlacement[i] = 0;
        }
    }

    for (int i = 0; i < guessLength; i++) {
        

        for (int j = 0; j < guessLength; j++) {

            if (userGuess[i] == correctWord[i]) {
                continue;
            }

            else if ((userGuess[i] == correctWord[j] && (checkedPlacement[i] == 0))) {
                checkedGuess[i] = 'Y';
                checkedPlacement[i] = 1;
            }
        }
    }

    for (int i = 0; i < guessLength; i++) {
        printf("%c ", (char)checkedGuess[i]); 
    }
    printf("\n");

}

int main() {
    const char *correctWord = "CRANE";
    const char *userGuess1 = "PAINS";

    //checkWordPlacement(correctWord, userGuess1);

    checkFullWordPlacement(correctWord, userGuess1);
}