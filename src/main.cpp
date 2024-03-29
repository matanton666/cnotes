#include "note.hpp"
#include "listNote.hpp"
#include "textNote.hpp"
#include "Folder.hpp"
#include "console.hpp"
#include <fstream>
#include <iostream>
#include <cstring>

const int OPTION = 2; // index of option in the argv

bool saveToFile(vector<Note*> notes);
vector<Note*> readFromFile();
Note *deserialize(json j);


int main(int argc, char *argv[])
{
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
            if (option == "folder") {
                notes.push_back(note);
            }
            else {
                notes.insert(notes.begin(), note); // push front
            }
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

    case ADD: {
        addNoteToFolder(notes, option);
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
    file.open(".notes"); // write to file
    if (file.fail()) {
        std::cerr << "could not open database for storing notes";
        return false;
    }
    json j;
    j["notes"];

    for (auto note : notes)
    {
        j["notes"].push_back(note->serialize());
    }
    file << j;

    file.close();
    return true;
}

vector<Note*> readFromFile() {
    vector<Note*> notes;
    std::ifstream file;

    file.open(".notes");
    if (file.fail()) {
        std::cerr << "could not open database file for reading saved notes\n";
        return notes;
    }
    json data = json::parse(file);
    // for each entry in data create a note and add it to notes
    for (auto entry : data.at("notes").get<json>())
    {
        notes.push_back(deserialize(entry));
    }
    return notes;
}

    

Note* deserialize(json j) {
    switch (j.at("type").get<int>())
    {
    case TEXT_NOTE:
        return new TextNote(
            j.at("title").get<string>(),
            j.at("content").get<string>()
            );
        break;

    case LIST_NOTE: {
        vector<string> list;
        for (auto entrie : j.at("content").get<json>())
        {
            list.push_back(entrie.get<string>());
        }
        return new ListNote(
            j.at("title").get<string>(),
            list
            );
        break;
    }

    case FOLDER_NOTE: {
        Folder* f = new Folder(
            j.at("title").get<string>()
            );
        for (auto note : j.at("content").get<json>())
        {
            f->append(deserialize(note));
        }
        return f;
        break;
    }
    
    default:
        std::cerr << "could not deserialize note";
        break;
    }
    return nullptr;
}