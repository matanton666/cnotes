#pragma once

#include "note.hpp"
#include <vector>

using std::vector;

class Folder : Note
{
private:
    vector<Note*> _notes;
public:
    Folder(string name, unsigned int id, vector<Note*> notes);
    Folder(string name, unsigned int id);
    ~Folder();

    virtual void print() const override;
    void set(vector<Note*> notes);
    void append(Note* note);
    Note* get(unsigned int pos) const;
};