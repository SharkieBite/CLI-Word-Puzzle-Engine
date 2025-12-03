# Assignment: The Team Assignment


**Names:** 
- Michael Mondaini [@SharkieBite](https://www.github.com/SharkieBite)
- Sriha Kanthasamy [@sriha-k](https://www.github.com/sriha-k)
- Sabrina Leung [@BrinaLeung](https://www.github.com/BrinaLeung)
- Axell Panganiban [@axell8560](https://www.github.com/axell8560)

**Date:** December 3rd, 2025
**Course:** SFWRENG 2XC3 - Software Development Basics

---------------------------------------------------------

This repository contains a Linux command line utility named `playWords`, written in C, that is based on the New York Times game Wordle. The game will start with the default 5 letter word and an amount of guesses per difficulty. The game starts off with the user in located in the main menu screen, being able to choose to play the game based on a difficulty. The user will then be able to guess a word according to the amount of letters the current level is set towards. Depending on the difficulty, there will be a set amount of guesses the user gets. After a round ends successfully, the user will be able to decide to play again and the user will be upgraded to a higher level, which is a longer length of a word. 

## Functionality of the program:
- Outputs the welcome and main menu screen for the user to interact with, `playWords`
- Outputs only the main menu screen for the user to interact with, `playWords -w`

## Files in the repository:
- `words.c`, contains the user interface that the user interacts with from the command line. This file is coded in C.
- `main.c`, contains the main program that calls the needed functions, with the proper flags. This file is coded in C.
- `checkletter.c`, contains the the functions for checking a letter placement. This file is coded in C.
- `checkWord.c`, contains the the functions for checking a word placement. This file is coded in C.
- `chooseWord.c`, contains the the functions getting a word to play the game. This file is coded in C.
- `.github/workflows/build.yml`, compiles the program on every push to ensure good working of the program and its files.
