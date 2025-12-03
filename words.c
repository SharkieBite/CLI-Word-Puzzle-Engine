/* Michael Mondaini, 400591695, December 3rd, 2025
*
* Description: Contains the program that the user interacts with from the command line and deals with guessing each word, and playing the game. This file is coded in C.
*/

//Imports the necessary modules needed for the program
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "playWords.h"

//Defines a function which handles with outputting welcome screen, returning nothing
void displayWelcome() {
 
    //Outputs the start of the bold white colour
    printf("\x1b[1m\x1b[37m");

    //Outputs the welcome text being in a ASCII banner format
    printf("   _       __     __                              __           _       __              __    \n"
           "  | |     / /__  / /________  ____ ___  ___      / /_____     | |     / /___  ________/ /____\n"
           "  | | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\    / __/ __ \\    | | /| / / __ \\/ ___/ __  / ___/\n"
           "  | |/ |/ /  __/ / /__/ /_/ / / / / / /  __/   / /_/ /_/ /    | |/ |/ / /_/ / /  / /_/ (__  ) \n"
           "  |__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/    \\__/\\____/     |__/|__/\\____/_/   \\__,_/____/  \n");

    //Outputs the end of bold white colour formatting text
    printf("\x1b[0m");

    //Outputs a text seperator to the screen
    printf("\x1b[90m========================================================================================================\x1b[0m\n");

    //Outputs the loading text to the screen, and the start of the loading bar
    printf("Loading: 0%%\n");
    printf("[");

    //Defines a for loop that loops through 100 times, being the loading time
    for (int i = 0; i < 100; i++) {

        //Defines the current percentage to be outputted
        int currentPercentage = (i + 1);

        //Sleeps the output for 0.1 seconds, for the loading bar
        usleep(10000); 

        //Outputs the green loading chunk for the loading bar
        printf("\x1b[42m \x1b[0m");

        //Updates the current percentage above by moving the user's cursor, up one line and to column ten
        printf("\x1b[s\x1b[1A\x1b[10G");
        
        //Outputs the new percentage, in the cursor position
        printf("%d%%", currentPercentage);

        //Outputs the cursor to the original position, to the loading bar
        printf("\x1b[u");

        //Flushes the standard output
        fflush(stdout); 
    }

    //Outputs the end of the loading bar, with a new line character
    printf("]\n");

    //Outputs a text seperator to the screen
    printf("\x1b[90m========================================================================================================\x1b[0m\n");

    //Calls the display main menu function to display the main menu after the welcome screen
    displayMainMenu();
}

//Defines a function which handles with outputting the main menu screen, returning nothing
void displayMainMenu() {

    //Defines the user's selection for the main menu and sub menu
    int userMenuSelection = 0;
    int userSubMenuSelection = 0;

    //Outputs the main menu text for selecting which sub-menu
    puts("\x1b[90m|\x1b[0m     \x1b[1m\x1b[37mMain Menu      \x1b[0m\x1b\x1b[90m|\x1b[0m\n━━━━━━━━━━━━━━━━━━━━━━\x1b[0m\n\x1b[34m[1]\x1b[0m: Start Game\n\x1b[34m[2]\x1b[0m: View Game Credits\n\x1b[34m[3]\x1b[0m: --help\n\x1b[34m[4]\x1b[0m: Quit");
    
    //Determines if the user's menu selection input has encountered an error
    if (scanf("%d", &userMenuSelection) != 1) {

        //Exits the program with code one
        exit(1);
    }

    //Determines if the user's menu selection input has selected option one
    else if (userMenuSelection == 1) {

        //Calls the user difficulty function to get the user's difficulty level to start the game
        getUserDifficulty();
    }

    //Determines if the user's menu selection input has selected option two
    else if (userMenuSelection == 2) {

        //Outputs the credits menu, to the user
        puts("\x1b[90m|\x1b[0m     \x1b[1m\x1b[37mCredits      \x1b[0m\x1b\x1b[90m|\x1b[0m\n━━━━━━━━━━━━━━━━━━━━━━\x1b[0m\nTeam S.A.M.S:\n\x1b[34mMichael Mondaini\x1b[0m\n\x1b[34mSriha Kanthasamy\x1b[0m\n\x1b[34mSabrina Leung\x1b[0m\n\x1b[34mAxell Panganiban\x1b[0m\n");
    
        //Outputs the back to main menu option to the user
        printf("\x1b[34m[1]\x1b[0m: Back to Main Menu\n");
    
        //Determines if the user's sub menu selection input has encountered an error
        if (scanf("%d", &userSubMenuSelection) != 1) {

            //Exits the program with code one
            exit(1);
        }

        //Determines if the user's sub menu selection input has selected option one
        else if (userSubMenuSelection == 1) {

            //Calls the user main menu function again to revert back
            displayMainMenu();
        }

        //Defaults to this statement if the user has selected a invalid selection
        else {

            //Calls the display usage function to display an error message to the user
            displayUsage("Error: Incorrect menu selection", false);
        }
    }
    

    //Determines if the user's menu selection input has selected option three
    else if (userMenuSelection == 3) {

        //Outputs --help flags
        puts("\x1b[90m|\x1b[0m                            \x1b[1m\x1b[37m--help                              \x1b[0m\x1b\x1b[90m|\x1b[0m\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
        puts("Welcome to Words, a level-based guessing game.");
        puts("Main menu will be displayed");
        puts("Options: ");
        puts("      [1] Start Game                  Starts the game");
        puts("      [2] View Game Credits           Display game credits");
        puts("      [3] --help                      Shows this help message");
        puts("      [4] Quit                        Quits the game");
        puts(" ");
        puts("Select difficulty menu will be display if [1] is chosen");
        puts("Options: ");
        puts("      [1] Easy                        Starts level 1 on easy");
        puts("      [2] Medium                      Starts level 1 on medium");
        puts("      [3] Hard                        Starts level 1 on hard");
        puts(" ");

        //Outputs the back to main menu option to the user
        printf("\x1b[34m[1]\x1b[0m: Back to Main Menu\n");

        //Determines if the user's sub menu selection input has encountered an error
        if (scanf("%d", &userSubMenuSelection) != 1) {

            //Exits the program with code one
            exit(1);
        }

        //Determines if the user's sub menu selection input has selected option one
        else if (userSubMenuSelection == 1) {

            //Calls the user main menu function again to revert back
            displayMainMenu();
        }

        //Defaults to this statement if the user has selected a invalid selection
        else {

            //Calls the display usage function to display an error message to the user
            displayUsage("Error: Incorrect menu selection", false);
        }
    }

    //Determines if the user's menu selection input has selected option three
    else if (userMenuSelection == 4) {

        //Outputs that the program is now exiting
        puts("\x1b[90m|\x1b[0m     \x1b[1m\x1b[37mMain Menu      \x1b[0m\x1b\x1b[90m|\x1b[0m\n━━━━━━━━━━━━━━━━━━━━━━\x1b[0m\nQuitting Game.");
        
        //Exits the program with code one
        exit(1);
    }

    //Defaults to this statement if the user has selected a invalid selection
    else {

        //Calls the display usage function to display an error message to the user
        displayUsage("Error: Incorrect menu selection", false);
    }
}

//Defines a function which handles with getting the user's difficulty, returning nothing
void getUserDifficulty() {

    //Defines the current user level and tries
    int userDifficultySelection = 0;
    int currentUserLevel = 1;
    int currentUserTries = 0;

    //Outputs the header for selecting the game's difficulty, and the different options
    puts("\x1b[90m|\x1b[0m     \x1b[1m\x1b[37mSelect Difficulty      \x1b[0m\x1b\x1b[90m|\x1b[0m\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\x1b[0m\n\x1b[34m[1]\x1b[0m: Easy Mode\n\x1b[34m[2]\x1b[0m: Medium Mode\n\x1b[34m[3]\x1b[0m: Hard Mode\n\x1b[34m[4]\x1b[0m: Quit");

    //Determines if the user's menu selection input has encountered an error
    if (scanf("%d", &userDifficultySelection) != 1) {

        //Exits the program with code one
         exit(1);
    }

    //Determines if the user's menu selection input has selected option one
    else if (userDifficultySelection == 1) {

        //Calls the play game function, for the game to be played on 8 tries
        playGame(8);
    }

    //Determines if the user's menu selection input has selected option two
    else if (userDifficultySelection == 2) {

        //Calls the play game function, for the game to be played on 6 tries
        playGame(6);
    }

    //Determines if the user's menu selection input has selected option three
    else if (userDifficultySelection == 3) {

        //Calls the play game function, for the game to be played on 4 tries
        playGame(4);
    }

    //Determines if the user's menu selection input has selected option four
    else if (userDifficultySelection == 4) {

        //Outputs that the program is now exiting
        puts("\x1b[90m|\x1b[0m     \x1b[1m\x1b[37mMain Menu      \x1b[0m\x1b\x1b[90m|\x1b[0m\n━━━━━━━━━━━━━━━━━━━━━━\x1b[0m\nQuitting Game.");
        
        //Exits the program with code one
        exit(1);
    }

    //Defaults to this statement if the user has selected a invalid selection
    else {

        //Calls the display usage function to display an error message to the user
        displayUsage("Error: Incorrect menu selection", false);
    }
}

//Defines a function which handles with playing the game, returning nothing
void playGame(int userAttempts) {

    //Defines the guess and lives variables for keeping track of attempts
    char guess[10];
    int lives = 0;
    int userNextLevelSelection = 0;

    //Defines the current word length and starting number of attempts
    int wordLength = 5;
    int startingLives = userAttempts; 

    //Defines a while loop that loops through until the word length is greater than 8
    while (wordLength <= 8) {

        //Outputs the level header
        printf("\x1b[90m|\x1b[0m     \x1b[1m\x1b[37mLevel %d      \x1b[0m\x1b\x1b[90m|\x1b[0m\n━━━━━━━━━━━━━━━━━━━━━\x1b[0m\n", wordLength - 4);

        //Defines the current correct word, by calling the choose word function with the current word length
        char *currentCorrectWord;
        currentCorrectWord = chooseWord(wordLength);

        //Copies the current correct word, without the '/r' and '\n', replaced with a null terminator
        currentCorrectWord[strcspn(currentCorrectWord, "\r")] = '\0';
        currentCorrectWord[strcspn(currentCorrectWord, "\n")] = '\0';

        //Defines a for loop that loops through the number of letters in the correct word
        for (int i = 0; currentCorrectWord[i]; i++) {

            //Sets the current correct letter, to be that letter however lowercase
            currentCorrectWord[i] = tolower(currentCorrectWord[i]);
        }

        //Defines the number of lives to be equal to starting lives
        int lives = startingLives;

        //Defines a infinite while loop, that won't stop looping until a break statement is reached
        while (1) {

            //Outputs the level header, containing the attempts and more
            printf("\x1b[34m[Level]\x1b[0m: %d \x1b[90m|\x1b[0m \x1b[34m[Word Length]\x1b[0m: %d \x1b[90m|\x1b[0m \x1b[34m[Attempts Left]\x1b[0m: %d\nUser Guess: ", wordLength - 4, wordLength, lives);

            //Determines if the user's menu selection input has encountered an error
            if (scanf("%s", guess) != 1) {

                //Exits the program with code one
                exit(1);
            }
            
            //Defines a for loop that loops through each letter in the guess word
            for (int i = 0; guess[i]; i++) {

                //Converts the guess letter to a lowercase
                guess[i] = tolower(guess[i]);
            }

            //Determines if the check word function is equal to true by calling it
            if (checkWord(wordLength - 4, guess) == true) {

                //Outputs the evaluated guess string
                printf("Evaluated Guess: ");
                    
                //Calls the check letter function to check the letter's
                checkLetter(guess, currentCorrectWord, &lives, wordLength);

                //Outputs the string seperator
                printf("\x1b[90m-----------------------\x1b[0m\n");

                //Determines if the guess and correct word are the same, using the string comparsion method
                if (strcmp(guess, currentCorrectWord) == 0) {

                    //Outputs to the user that the guess is correct
                    printf("\x1b[32mUser Guess is Correct! Word was %s.\x1b[0m\n", currentCorrectWord);

                    //Outputs the string seperator
                    printf("\x1b[90m-----------------------\x1b[0m\n");
                    
                    //Outputs the next level header
                    puts("\x1b[90m|\x1b[0m     \x1b[1m\x1b[37mNext Level?      \x1b[0m\x1b\x1b[90m|\x1b[0m\n━━━━━━━━━━━━━━━━━━━━━━\x1b[0m\n\x1b[34m[1]\x1b[0m: Yes\n\x1b[34m[2]\x1b[0m: No");

                    //Determines if the user's menu selection input has encountered an error
                    if (scanf("%d", &userNextLevelSelection) != 1) {

                        //Exits the program with code one
                        exit(1);
                    }

                    //Determines if the user's menu selection input has selected option one
                    else if (userNextLevelSelection == 1) {

                        //Adds one to the new word length, and two to the starting attempts
                        wordLength++;
                        startingLives += 2;

                        //Breaks out of the while loop
                        break;
                    }

                    //Defaults to this statement if a selection is not made
                    else {

                        //Exits the program with code one
                        exit(1);
                    }
                }

                //Determines if the number of attempts is equal to zero
                if (lives == 0) {

                    //Outputs the level has been lost, and the current word
                    printf("\x1b[31mLevel Lost. The word was: %s\x1b[0m\n", currentCorrectWord);

                    //Breaks out of the while loop
                    break;
                }
            }

            //Defaults to this statement if word is not valid
            else {

                //Outputs that the word is invalid
                puts("Invalid word. Try again.");
            }
        }
    }

    //Outputs that all levels have been beat
    printf("You beat all levels\n");
}

//Defines a function which handles with outputting errors to standard error, taking two parameter input to function
void displayUsage(const char *errorMessage, bool displayUsage) {

    //Determines if the error message is not empty to output the message
    if (!(strcmp(errorMessage,"") == 0)) {

        //Outputs to the user the given error message given from parameters, to standard error
        fprintf(stderr, "%s\n", errorMessage);
    }

    //Determines if the usage error is needed to be outputted, using the value given in the parameters
    if (displayUsage) {

        //Outputs to the user the given usage message in parameters, to standard error
        fprintf(stderr, "Usage: playWords\n");
    }

    //Exits the program with a failure
    exit(EXIT_FAILURE);
}

//Defines the main function, that the user uses
int main(int argc, char *argv[]) {

    //Calls the welcome function when the program is lanuched
    displayWelcome();
}