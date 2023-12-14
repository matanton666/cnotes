#pragma once
#include "note.hpp"



class TextNote : public Note
{
private:
    string _content;
public:
    TextNote(string title, string content);
    TextNote(string title);
    TextNote(const TextNote& other);
    ~TextNote();

    virtual void print() const override;
    virtual void printHead() const override;

    void append(string newContent);
    void set(string newContent);
};
