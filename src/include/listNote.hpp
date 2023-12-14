#pragma once

#include "note.hpp"
#include <vector>

using std::vector;

class ListNote : public Note
{
private:
    vector<string> _list;
    void printList() const;

public:
    ListNote(string title, vector<string> list);
    ListNote(string title);
    ~ListNote();

    virtual void print() const override;
    virtual void printHead() const override;
    virtual const unsigned int getClassSize() const override;
    virtual json serialize() const override;

    void append(string entrie);
    void set(vector<string> list);

};