/*
Sriha Kanthasamy
400571386
Purpose: To implement a code to check if the word that the user enters is a word in the text file.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int main (){

    //variables
    char option, word[10], guess[10];
    char *fileChoice = NULL;
    bool exists = false;

    //menu
    printf("Word Length Options:\na. 5 letter word\nb. 6 letter word\nc. 7 letter word\nd. 8 letter word");

    //word length options
    do{    
        printf("\nWhich word length option would you like (a-d): ");
        scanf(" %c", &option);
        if (option == 'a'){
            fileChoice = "WordFiles/5word.txt";
        }
        else if (option == 'b'){
            fileChoice = "WordFiles/6word.txt";
        }
        else if (option == 'c'){
            fileChoice = "WordFiles/7word.txt";
        }
        else if (option == 'd'){
            fileChoice = "WordFiles/8word.txt";
        }
        else{
            printf("\nInvalid input, must be a, b, c, or d.");
            scanf("%c", &option);
        }
    }while(fileChoice == NULL);

    //opening file
    FILE *file;
    file = fopen(fileChoice, "r");
    if (file == NULL){
        printf("Error");
        return EXIT_FAILURE;
    }

    printf("\nEnter word: ");
    scanf("%9s", guess);

    while (fscanf(file, "%9s", word) == 1 && !exists){
        if (strcmp(word, guess) == 0){
            exists = true;
        }
    }
    
    fclose(file);

    if (!exists){
        printf("\nNot in word list!\n");
    }
    else{
        printf("\nWorks\n");
    }
    return EXIT_SUCCESS;

}//end main