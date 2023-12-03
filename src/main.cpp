#include "note.hpp"
#include "listNote.hpp"
#include "textNote.hpp"
#include "Folder.hpp"
#include "console.hpp"

const int OPTION = 2;

int main(int argc, char* argv[]) {
    vector<Note*> notes;
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

    for (auto note : notes) 
    {
        delete note;
    }

    return 0;
}
 