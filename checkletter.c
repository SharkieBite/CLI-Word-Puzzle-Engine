
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checkletter.h"

int main(int argc, char *input[]) {
    char *answer = "hello";
    char *guess;
    int lives = 5;
    int *attempts = &lives;
    int level = 5;

    if (argc >= 2 && strcmp(input[1], "--help") == 0) {
        help();
        return 0;
    }
    puts("Enter guess");
    while (1) {
        if (scanf("%s", guess) != 1) {
            printf("Answer was \033[32m%s\033[0m\n", answer);
            return 0;
        }
        // to_lower(guess);
        checkLetter(guess, answer, attempts, level);
        if (*attempts == 0) {
            return 0;
        }
    }
    return 0;
}

int checkLetter(char *guess, char *answer, int *attempts, int level) { //Checks if letters match
    int checker = 1;
    // printf("%s\n", answer);
    // if (strlen(guess) == level) {
    *attempts -= 1;
    for (int i=0; i< level; i++) {
        if (strchr(answer, guess[i]) != NULL) {
            if (guess[i] == answer[i]) {
                printf("\033[32m%c\033[0m", guess[i]); //green
            }
            else {
                printf("\033[33m%c\033[0m", guess[i]); //yellow
                checker = 0;
            }
        }
        else {
            printf("\033[31m%c\033[0m", guess[i]); //red
            checker = 0;
        }
        // printf(" guess: %c, answer: %c\n", guess[i], answer[i]);
    }
    puts("");
    if (checker == 1) {
        puts("You win!");
        exit(0);
    }
    else if (*attempts == 0) { 
        puts("You are out of attempts");
        printf("Answer was \033[32m%s\033[0m\n", answer);
        return 0;
    }
    // }
}

int help() {
    puts("lettercheck v1.0.0");
    puts("Checks if letters in guess are in right spot");
    puts("Usage: letterCheck(guess, answer, attempts, level)\n");
    puts("<guess> \t\tchecks users guess");
    puts("<answer> \t\tcompares letters in guess to answer");
    puts("<attempts> \t 1-10 \tgives number of current attempts user has");
    puts("<level> \t 5-8 \tchecks first <level> letters in answer");
    puts("--help \t\t\tdisplay this help and exit\n");
    puts("Examples:\nletterCheck(hello, hello, 1, 5)\t\tTells user they win.");
    puts("letterCheck(fraud, hello, 1, 5)\t\tTells user they lose.");
    return 0;
}
