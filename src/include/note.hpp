#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;

class Note
{
private:
    string _title;
    unsigned int _id;
    static unsigned int _idCount;
    
    static unsigned int generateId();

public:
    Note(string title);
    virtual ~Note() {
        _idCount--;
    }


    string getTitle() const;
    unsigned int getId() const;
    virtual void printHead() const;
    virtual void print() const = 0;

    // TODO: add serialize and deserialize for saving in file
};


