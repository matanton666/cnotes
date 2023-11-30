#pragma once
#include "note.hpp"

#include <iostream>

using std::cout;


class TextNote : public Note
{
private:
    string _content;
public:
    TextNote(string title, unsigned int id, string content);
    TextNote(string title, unsigned int id);
    ~TextNote();

    virtual void print() const override;

    void append(string newContent);
    void set(string newContent);
};
