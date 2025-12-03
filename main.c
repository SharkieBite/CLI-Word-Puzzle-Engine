//Imports the necessary modules needed for the program
#include <stdio.h>
#include <string.h>
#include "words.h"

//Defines the main function, that the user uses
int main(int argc, char *argv[]) {

    //Determines if exactly two arguments have been entered
    if (argc == 2) {

        //Determines if the first flag used in the program is the '-w' flag
        if (strcmp(argv[1], "-w") == 0) {

            //Calls the main menu function when the program is lanuched with the '-w' flag
            displayMainMenu();
        }
    }

    //Defaults to this statement if the '-w' flag is used
    else {

        //Calls the welcome function when the program is lanuched
        displayWelcome();
    }
}