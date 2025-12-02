//Defines constant variable that will never change throughout the program
#include <stdbool.h>
#define MAX_GUESSES 6        
#define MAX_WORD_LENGTH 6    
#define MAX_LINE_LENGTH 16

//Declares the functions as a prototypes
char *chooseWord(int number);
bool checkWord(int level, char *guess);
int checkLetter(char *guess, char *answer, int *attempts, int level);
bool isNewGuess(const char *word, char oldGuesses[][MAX_WORD_LENGTH], int guessCount);
void getUserDifficulty();
void displayMainMenu();
void playGame(int userAttempts);
