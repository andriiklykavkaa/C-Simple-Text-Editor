#include <stdbool.h>
#include <stdio.h>

#include "commands.h"
#include "file_interaction.h"


void handleCommand()
{
    int command;
    printf("Choose the command: ");
    scanf(" %d", &command);

    switch(command)
    {
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
        default:
            printf("This command is not implemented\n");
            break;
    }
}


void cleanConsole() {
 // To be implemented
}

int main()
{
    printf("Welcome to the text editor!\n To see the list of commands, call command '0\n");
    while(true)
    {
        handleCommand();
    }
}