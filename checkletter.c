/* Axell Panganiban 400588161 Monday December 1 2025
*
* This code compares each letter in guess to answer and prints the letters out in different colours depending
* on if the letter in the right spot, in the wrong spot, or not in the word at all
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int help();
int checkLetter(char *guess, char *answer, int *attempts, int level);

/* Main method
*
* Parameters:
* None
*
* Runs checkLetter function with hello as the answer
*/

int main(int argc, char *input[]) { //Main method
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
        checkLetter(guess, answer, attempts, level);
        if (*attempts == 0) {
            return 0;
        }
    }
    return 0;
}

/* CheckLetter function
*
* Parameters:
* char *guess - User's current guess
* char *answer - Current answer
* int *attempts - Number of remaining attempts
* int level - Amount of letters in word
*
* Compares letters in guess and answer
* Displays guess with red letters for letters that aren't in answer, 
* yellow for letters that are present but in the wrong spot, and green for correctly placed letters
* Decreases attempts by 1 each time function is called
* Prints victory message if user guesses answer, lose message if user runs out of attempts
*/

int checkLetter(char *guess, char *answer, int *attempts, int level) { //Method to check if letters match
    int checker = 1; //Checker if all letters are in correct placement
    *attempts -= 1; //Decrease attempt count by 1
    for (int i=0; i< level; i++) { //For each letter in guess
        if (strchr(answer, guess[i]) != NULL) { //If letter is in answer
            if (guess[i] == answer[i]) { //If letter is in right placement
                printf("\033[32m%c\033[0m", guess[i]); //green
            }
            else { //If letter isn't in right placement
                printf("\033[33m%c\033[0m", guess[i]); //yellow
                checker = 0; //Guess isn't correct
            }
        }
        else { //Else if letter isn't in word
            printf("\033[31m%c\033[0m", guess[i]); //red
            checker = 0;
        }
    }
    puts("");
    if (checker == 1) { //If guess is correct
        puts("You win!");
        exit(0);
    }
    else if (*attempts == 0) {  //If user runs out of attempts
        puts("You are out of attempts");
        printf("Answer was \033[32m%s\033[0m\n", answer);
        return 0;
    }
}

int help() { //Help function
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
