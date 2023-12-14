#pragma once

#include "note.hpp"
#include <vector>

using std::vector;

class Folder : public Note
{
private:
    vector<Note*> _notes;
public:
    Folder(string name, vector<Note*> notes);
    Folder(string name);
    ~Folder();

    virtual void print() const override;
    virtual void printHead() const override;
    virtual const unsigned int getClassSize() const override;
    virtual json serialize() const override;

    void set(vector<Note *> notes);
    void append(Note* note);
    Note* get(unsigned int pos) const;
};