#include "include/Folder.hpp"

Folder::Folder(string name, unsigned int id) : 
    Note(name, id)
{
}

Folder::Folder(string name, unsigned int id, vector<Note*> notes) : 
    Note(name, id)
{
    set(notes);   
}

Folder::~Folder()
{
}

void Folder::print() const
{
    for (int i = 0; i < _notes.size(); i++)
    {
        _notes[i]->print();
    }
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
