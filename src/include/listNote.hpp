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
    ListNote(string title, unsigned int id, vector<string> list);
    ListNote(string title, unsigned int id);
    ~ListNote();

    virtual void print() const override;
    void append(string entrie);
    void set(vector<string> list);

};