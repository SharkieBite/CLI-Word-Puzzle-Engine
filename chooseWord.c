#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 16

////this function that the number of word and opens the coresponding file, chooses a word and returns it.
char *chooseWord(int number) {
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
