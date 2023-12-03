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
    REMOVE,
    INVALID,
    HELP,
};

Commands getCommand(char* argv[]);

void printHelp();
Note* newNote(string type);
bool removeNote(vector<Note*>& notes, string option);
void listNotes(vector<Note*>& notes);
void showNote(vector<Note*>& notes, string option);

string getUserInput(string message);
Note* getNoteFromNotes(vector<Note*>& notes, string option);