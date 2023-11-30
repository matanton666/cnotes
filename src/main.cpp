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
    case NEW: {
        Note* note = newNote(option);
        if (note != nullptr) {
            notes.push_back(note);
        }
        break;
    }

    default:
        break;
    }

    
    return 0;
}
 