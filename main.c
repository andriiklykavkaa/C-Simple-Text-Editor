#include <stdio.h>
#include <stdlib.h>

#include "commands.h"


#define clearScreen() printf("\033[2J\033[H");
#define true 1
#define false 0

void handleCommand() {
    char input[10];
    int command = -1;

    printf("Choose the command: ");

    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &command);

    system("clear");
    switch (command) {
        case 0:
            showInstructions();
            break;
        case 1:
            appendText();
            break;
        case 2:
            addNewLine();
            break;
        case 3:
            saveFile();
            break;
        case 4:
            loadFile();
            break;
        case 5:
            printText();
            break;
        case 6:
            insertByLineAndIndex();
            break;
        case 7:
            searchText();
            break;
        case 8:
            exitProgram();
            break;
        default:
            printf("This command is not implemented\n");
            break;
    }
}

int main() {
    printf("Welcome to the text editor!\n To see the list of commands, call command '0\n");
    while (true) {
        handleCommand();
    }
}
