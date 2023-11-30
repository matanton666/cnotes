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
public:
    Note(string title, unsigned int id);
    ~Note();

    string getTitle() const;
    unsigned int getId() const;
    virtual void print() const = 0;
    // TODO: add serialize and deserialize for saving in file
};


