#include "include/console.hpp"

Commands getCommand(char* argv[]) 
{
    string operation = argv[1];
    if (operation == "new") return NEW;
    else if (operation == "edit") return EDIT;
    else if (operation == "show") return SHOW;
    else if (operation == "list") return LIST;
    else return INVALID;
}


void printHelp()
{
    cout << "usage: cnotes <COMMAND> <OPTIONS>\n\n";
    cout << "commands: \n\
    new <type> - create new note of a type \n\
    edit <id> - edit a note / folder \n\
    show <id> - show a notes contents \n\
    list - list all notes and folders \n\
    \n\
types: text, list, folder\n\
    ";

}

Note* newNote(string type)
{
    if (type == "text") {
        string title = getUserInput("enter title");
        string content = getUserInput("enter content");
        return new TextNote(title, content);
    }

    return nullptr;
}

bool editNote()
{
    return false;
}

void listNotes()
{
}

void showNote()
{
}

string getUserInput(string message)
{
    string input;
    cout << message << "\n-> ";
    std::getline(std::cin, input);
    return input;
}
