#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

// #include "playWordle.h"
// #include "checkletter.h"

#define MAX_GUESSES 6        
#define MAX_WORD_LENGTH 6    
#define MAX_LINE_LENGTH 16

char *chooseWord(int number);
bool checkWord(int level, char *guess);
int checkLetter(char *guess, char *answer, int *attempts, int level);
char * to_lower(char *string);

int main(int argc, char *input[]) {
    int level;
    int lives = 0;
    int *attempts = &lives;
    char *answer;
    char *guess;

    if (argc > 1 && strcmp(input[1], "--help") == 0){
        printf("Usage: Help Function\n");
        printf("Welcome to Words, a level-based guessing game.\n");
        printf("You will:\n");
        printf("  - Enter a word size between 5 and 8 letters.\n");
        printf("  - Enter the number of attempts you prefer (1–10).\n");
        printf("  - Guess words of the correct length.\n");
        printf("  - Words must exist in the dictionary.\n");
        printf("  - Colours:\n");
        printf("       Green  = correct letter and position\n");
        printf("       Yellow = letter exists but wrong position in word\n");
        printf("       Red    = letter does not exist in word\n");
    return 0;  
    }

    puts("Enter wordle size between 5 and 8 letters");
        if (scanf("%d", &level) != 1) {
            fprintf(stderr, "Invalid entry\n");
            exit(1);
        }
        else if (5 > level || level > 8) {
            fprintf(stderr, "Invalid word size\n");
            exit(1);
        }

    puts("Enter number of attempts you have (1-10)");
    if (scanf("%d", &lives) != 1) {
        fprintf(stderr, "Invalid entry\n");
        exit(1);    
    }
    else if (1 > lives || lives > 10) {
        fprintf(stderr, "Invalid number of attempts\n");
        exit(1);    
    }

    answer = chooseWord(level);
    // to_lower(answer);
    // for (int i=0; i<strlen(answer); i++) {
    //     answer[i] = tolower(answer[i]);
    // }

    puts("Enter guess");
    while (1) {
        if (scanf("%s", guess) != 1) {
            printf("Answer was \033[32m%s\033[0m\n", answer);
            return 0;
        }
        // to_lower(guess);
        if (checkWord(level-4, guess) == true) {
            checkLetter(guess, answer, attempts, level);
            if (*attempts == 0) {
                return 0;
            }
        }
        else {
            puts("Invalid word. Try again");
        }
    }

}

char *chooseWord(int number) { //Chooses word with "number" amount of letters
    static char random_line[MAX_LINE_LENGTH];  // static so it persists after return
    char line[MAX_LINE_LENGTH];
    char filename[32];
    int line_count = 0;

    snprintf(filename, sizeof(filename), "WordFiles/%dword.txt", number);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Sorry, please choose a number between 5-8");
        return NULL;
    }

    srand(time(NULL));

    while (fgets(line, sizeof(line), file) != NULL) {
        line_count++;
        if (rand() % line_count == 0) {
            strcpy(random_line, line);
        }
    }

    fclose(file);

    random_line[strcspn(random_line, "\n")] = '\0';

    return random_line;
}

bool checkWord(int level, char *guess){ //Checks if guess is valid word

    //variables
    char word[10], *fileMain = NULL, *fileBank = NULL;
    bool found = false;

    //based on level, choosing the right textfiles
    if (level == 1){
        fileMain = "WordFiles/5word.txt";
        fileBank = "WordFiles/5wordbank.txt";
    }
    else if(level == 2){
        fileMain = "WordFiles/6word.txt";
        fileBank = "WordFiles/6wordbank.txt";
    }
    else if(level == 3){
        fileMain = "WordFiles/7word.txt";
        fileBank = "WordFiles/7wordbank.txt";
    }
    else if(level == 4){
        fileMain = "WordFiles/8word.txt";
        fileBank = "WordFiles/8wordbank.txt";
    }
    else{
        fprintf(stderr, "Error: Invalid level %d. Must be 1–4.\n", level);
        return false;
    }


    //going through main dictionary of files
    FILE *file = fopen(fileMain, "r");
    if (file == NULL){
        fprintf(stderr, "Error: Cannot open main textfile: %s\n", fileMain);
        return false;
    }

    while (fscanf(file, "%9s", word) == 1 && !found){
        if (strcmp(word, guess) == 0) {
            found = true;
        }
    }//end while loop
    fclose(file);

    if (found){
        return true;
    }

    //second dictionary of unique words
    file = fopen(fileBank, "r");
    if (file == NULL){
        fprintf(stderr, "Error: Cannot open wordbank file: %s\n", fileBank);
        return false;
    }

    while (fscanf(file, "%9s", word) == 1 && !found) {
        if (strcmp(word, guess) == 0) {
            found = true;
        }
    }//end while loop

    fclose(file);
    return found;



}//end main

int checkLetter(char *guess, char *answer, int *attempts, int level) { //Checks if letters match
    int checker = 1;
    // printf("%s\n", answer);
    if (strlen(guess) == level) {
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
        //if (strcmp(guess, answer) == 0) {
        //}
    }
    // else {
    //     puts("Invalid word length");
    // }
    // return 0;
}

// bool isNewGuess(const char *word, char oldGuesses[][MAX_WORD_LENGTH], int guessCount) {
//     for (int i = 0; i < guessCount; i++) {
//         if (strcmp(oldGuesses[i], word) == 0) {
//             printf("already guessed\n");
//             return false; 
//         }
//     }
//     return true; 
// }
