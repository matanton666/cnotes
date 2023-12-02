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
        string content = " ";

        string title = getUserInput("enter title");
        note = new ListNote(title);
        cout << "enter content (enter nothing to stop):\n";


        while (content != "") 
        {
            string query = "[+]";
            content = getUserInput(query);
            note->append(content);
        }
        // TODO: remove the last entrie

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
    int noteNum = std::stoi(option);

    if (noteNum <= 0 || noteNum > notes.size()) // invalid size
    {
        return false;
    }
    
    Note* note = notes[noteNum - 1];
    notes.erase(notes.begin() + noteNum - 1);
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
