#include <stdio.h>
#include <stdlib.h>

#include "commands.h"
#include "Buffer.h"


#define clearScreen() printf("\033[2J\033[H");
#define true 1
#define false 0

void handleCommand(Buffer *buffer) {

    char input[8];
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
            appendText(buffer);
            break;
        case 2:
            addNewLine(buffer);
            break;
        case 3:
            saveFile(buffer);
            break;
        case 4:
            loadFile(buffer);
            break;
        case 5:
            printText(buffer);
            break;
        case 6:
            insertByLineAndIndex(buffer);
            break;
        case 7:
            searchText(buffer);
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
    Buffer buffer = createBuffer();

    printf("Welcome to the text editor!\n To see the list of commands, call command '0\n");
    while (true) {
        handleCommand(&buffer);
    }
}