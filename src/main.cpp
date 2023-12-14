#include "console.hpp"
#include <fstream>
#include <iostream>
#include <cstring>

const int OPTION = 2; // index of option in the argv

bool saveToFile(vector<Note*> notes);
vector<Note*> readFromFile();

int main(int argc, char* argv[]) {
    vector<Note *> notes = readFromFile();
    string option;

    if (argc <= 1 || argc > 3) {
        printHelp();
        return 1;
    }

    if (argc == 3) {
        option = argv[OPTION];
    }

    switch (getCommand(argv))
    {
    case INVALID: {
        cout << "E: invalid command\n";
        printHelp();
        break;
    }

    case HELP: {
        printHelp();
        break;
    }

    case NEW: {
        Note* note = newNote(option);
        if (note != nullptr) {
            notes.push_back(note);
        }
        else {
            std::cerr << "`" << option << "` is not a valid type (use `help` for type list)";
        }
        break;
    }

    case REMOVE: {
        if (!removeNote(notes, option)) {
            std::cerr << "`" << option << "` is not a note number";
        }
        break;
    }

    case SHOW: {
        showNote(notes, option);
        break;
    }

    case LIST: {
        listNotes(notes);
        break;
    }

    default:
        break;
    }

    saveToFile(notes);

    for (auto note : notes) 
    {
        delete note;
    }

    return 0;
}
 



bool saveToFile(vector<Note*> notes) {
    std::ofstream file;
    file.open(".notes", std::ios::binary); // write to file
    if (file.fail()) {
        std::cerr << "could not open database for storing notes";
        return false;
    }

    for (auto note : notes)
    {
        file.write(reinterpret_cast<const char*>(note), note->getClassSize());
    }

    file.close();
    return true;
}

vector<Note*> readFromFile() {
    vector<Note*> notes;
    std::ifstream file;

    file.open(".notes", std::ios::binary);
    if (file.fail()) {
        std::cerr << "could not open database file for reading saved notes";
        return notes;
    }

    char* note = new char[sizeof(Note)]; 
    Note* n = nullptr;
    do {
        // FIXME: need to copy allocation of memory and create copy of note instead of using the casted one because of static functions and stuff...
        file.read(note, sizeof(Note));
        n = reinterpret_cast<Note*>(note);
        Note* newNote = nullptr;
        switch (n->getNoteType())
        {
            case TEXT_NOTE:{
                newNote = new TextNote(*reinterpret_cast<TextNote *>(note));
                break;
            }
            
            default:
                break;
        }

        if (newNote != nullptr) {
            notes.push_back(newNote);
        }
        else {
            std::cerr << "could not read note from file";
        }
    }
    while (!file.fail());
    delete[] note;
    return notes;
}

    

