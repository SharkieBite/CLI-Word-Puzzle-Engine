#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *input[]) {
    char answer[] = "hello";
    char guess[sizeof(answer)];
    for (int attempts = 6; attempts > 0; attempts--) {
        scanf(" %s", guess);
        if (sizeof(guess) == sizeof(answer)) {
            for (int i=0; i< sizeof(answer); i++) {
                if (strchr(answer, guess[i]) != NULL) {
                    if (guess[i] == answer[i]) {
                        printf("%c", guess[i]); //green
                    }
                    else {
                        printf("(%c)", guess[i]); //yellow
                    }
                }
                else {
                    printf("|%c|", guess[i]);
                }
            }
            puts("");
            if (strcmp(guess, answer) == 0) {
                puts("You win!");
                return 0;
            }
        }
        else {
        puts("Invalid word length");
        attempts ++;
        }
    }

    printf("\n");
    //printf("%s, %s", guess, answer);

    puts("You are out of attempts");

    return 0;
}