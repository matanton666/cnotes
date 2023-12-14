#include "include/console.hpp"
#include "console.hpp"

Commands getCommand(char* argv[]) 
{
    string operation = argv[1];
    if (operation == "new") return NEW;
    else if (operation == "edit") return EDIT;
    else if (operation == "show") return SHOW;
    else if (operation == "list") return LIST;
    else if (operation == "remove") return REMOVE;
    else if (operation == "help") return HELP;
    else if (operation == "add") return ADD;
    else return INVALID;
}


void printHelp()
{
    cout << "usage: cnotes <COMMAND> <OPTIONS>\n\n";
    cout << "commands: \n\
    help - show this message \n\
    new <type> - create new note of a type \n\
    edit <id> - edit a note / folder \n\
    remove <id> - remove a note / folder \n\
    show <id> - show a notes contents \n\
    show all - show all notes contents \n\
    list - list all notes and folders \n\
    add <id> - add note <id> to a folder \n\
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

    else if (type == "list") {
        ListNote* note;
        string content = "";

        string title = getUserInput("enter title");
        note = new ListNote(title);
        cout << "enter content (enter nothing to stop):\n";


        do
        {
            string query = "[+]";
            content = getUserInput(query);
            if (content != "") {
                note->append(content);
            }
        } while (content != "");

            return note;
    }

    else if (type == "folder") {
        string title;
        Folder* folder;

        title = getUserInput("enter title");
        folder = new Folder(title);

        return folder;
    }

    return nullptr;
}

bool removeNote(vector<Note*>& notes, string option)
{   
    Note* note = getNoteFromNotes(notes, option);
    if (note == nullptr) {
        return false;
    }

    notes.erase(notes.begin() + std::stoi(option) - 1);
    delete note;
    return true;
}

void listNotes(vector<Note*>& notes)
{
    for (auto note : notes) 
    {
        note->printHead();
    }
}

void showNote(vector<Note*>& notes, string option)
{
    if (option == "all") {
        for (int i = 0; i < notes.size(); i++)
        {
            notes[i]->print();
        }
    }
    else {
        getNoteFromNotes(notes, option)->print();
    }   
}

void addNoteToFolder(vector<Note*>& notes, string option)
{
    Note* note = getNoteFromNotes(notes, option);

    // check if note in valid
    if (note == nullptr) {
        std::cerr << "`" << option << "` is not a note number";
        return;
    }
    if (note->getNoteType() == FOLDER_NOTE) {
        std::cerr << "`" << option << "` is a folder\n(folders in folders are currently not supported)";
        return;
    }
    
    notes.erase(notes.begin() + std::stoi(option) - 1);
    listNotes(notes);

    // add note to folder
    string folderName = getUserInput("folder name");
    for (int i = 0; i < notes.size(); i++)
    {
        if (notes[i]->getTitle() == folderName) {
            Folder* folder = dynamic_cast<Folder*>(notes[i]);
            if (folder == nullptr) {
                std::cerr << "`" << folderName << "` is not a folder";
                return;
            }
            folder->append(note);
            return;
        }
    }
    std::cerr << "`" << folderName << "` is not a folder";
}

string getUserInput(string message)
{
    string input;
    cout << message << " -> ";
    std::getline(std::cin, input);
    return input;
}

Note *getNoteFromNotes(vector<Note *> &notes, string option)
{
    int noteNum = std::stoi(option);

    if (noteNum <= 0 || noteNum >= notes.size()) // invalid size
    {
        return nullptr;
    }
    return notes[noteNum - 1];
}
