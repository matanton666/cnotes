#pragma once

#include "note.hpp"
#include "listNote.hpp"
#include "textNote.hpp"
#include "Folder.hpp"


enum Commands
{
    NEW,
    EDIT,
    LIST,
    SHOW,
    INVALID,
};

Commands getCommand(char* argv[]);

void printHelp();
Note* newNote(string type);
bool editNote();
void listNotes();
void showNote(); 

string getUserInput(string message);