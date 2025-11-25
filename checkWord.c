/*
Sriha Kanthasamy
400571386
Purpose: To implement a code to check if the word that the user enters is a word in the text file.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

/*
Purpose: To create a help flag for this section of the code.
*/
void printHelp(){
    printf("Usage: Checking guess against valid list of words.\n");
    printf("Validates a guessed word, based on current level.\n");
    printf("Valid if:\n");
    printf("  - In normal textfile dictionary.\n");
    printf("  - In unique word textfile dictionary.\n");
}//end void printHelp

bool checkWord(int level, char *guess){

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
    file = fopen(fileMain, "r");
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