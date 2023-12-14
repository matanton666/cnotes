#pragma once
#include <string>
#include <iostream>
#include <istream>
#include <ostream>

using std::string;
using std::cout;

enum NoteType {
    ABSTRACT_NOTE,
    TEXT_NOTE,
    LIST_NOTE,
    FOLDER_NOTE
};

class Note
{
private:
    string _title;
    unsigned int _id;
    static unsigned int _idCount;
    
    static unsigned int generateId();

protected:
    NoteType _type;

public:

    Note(string title);
    virtual ~Note() {
        _idCount--;
    }

    string getTitle() const;
    unsigned int getId() const;
    const NoteType getNoteType() const;
    const unsigned int getClassSize() const;

    virtual void printHead() const;
    virtual void print() const = 0;

    virtual Note& operator=(const Note& other) // TODO: use this in reading from file
    {
        this->_id = generateId();
        this->_title = other._title;
        this->_type = other._type;
        return *this;
    }
};


