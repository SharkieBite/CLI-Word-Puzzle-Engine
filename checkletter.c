
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checkletter.h"

int main(int argc, char *input[]) {
    if (argc == 2 && strcmp(input[1], "--help") == 0) {
        help();
        return 0;
    }
    checkLetter(6);
    return 0;
}

int checkLetter(int attempts) {
    char answer[] = "hello";
    char guess[100];
    for (attempts; attempts > 0; attempts--) {
        scanf(" %s", guess);
        if (strlen(guess) == strlen(answer)) {
            for (int i=0; i< sizeof(answer); i++) {
                if (strchr(answer, guess[i]) != NULL) {
                    if (guess[i] == answer[i]) {
                        printf("\033[32m%c\033[0m", guess[i]); //green
                    }
                    else {
                        printf("\033[33m%c\033[0m", guess[i]); //yellow
                    }
                }
                else {
                    printf("\033[31m%c\033[0m", guess[i]); //red
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
    puts("You are out of attempts");

    return 0;
}

int help() {
    puts("lettercheck v1.0.0");
    puts("Checks if letters in guess are in right spot");
    puts("Usage: letterCheck(attempts)\n");
    puts("Attempts give number of guesses user has");
    puts("If <attempts> isn't given, default value is 6\n");
    puts("<attempts> \t 1-10 \tset attempts to <attempts>");
    puts("--help \t\t\tdisplay this help and exit\n");
    puts("Examples:\nletterCheck(6) \t\tGives user 6 guesses");
    return 0;
}
