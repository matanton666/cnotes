#include "include/Folder.hpp"

Folder::Folder(string name) : 
    Note(name)
{
    _type = FOLDER_NOTE;
}

Folder::Folder(string name, vector<Note*> notes) : 
    Folder(name)
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

const unsigned int Folder::getClassSize() const 
{
    return sizeof(*this);
}

json Folder::serialize() const 
{
    json j;
    j["title"] = getTitle();
    j["type"] = _type;
    j["id"] = getId();
    
    j["content"];
    for (int i = 0; i < _notes.size(); i++)
    {
        j["content"].push_back(_notes[i]->serialize());
    }

    return j;
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
