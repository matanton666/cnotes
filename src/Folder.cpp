#include "include/Folder.hpp"

Folder::Folder(string name) : 
    Note(name)
{
}

Folder::Folder(string name, vector<Note*> notes) : 
    Note(name)
{
    set(notes);   
}

Folder::~Folder()
{
    for (int i = 0; i < _notes.size(); i++)
    {
        delete _notes[i];
    }
}

void Folder::print() const
{
    for (int i = 0; i < _notes.size(); i++)
    {
        _notes[i]->print();
    }
}
void Folder::printHead() const
{
    Note::printHead();
    cout << " | Folder\n";
}

void Folder::set(vector<Note*> notes)
{
    _notes = notes;
}

void Folder::append(Note* note) 
{
    _notes.push_back(note);
}

Note* Folder::get(unsigned int pos) const
{
    if (pos >= _notes.size()) {
        throw "pos too big";
    }
    return _notes[pos];
}
