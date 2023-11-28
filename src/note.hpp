#pragma once
#include <string>

using std::string;

class Note
{
private:
    string _title;
public:
    Note(string title);
    ~Note();
};

Note::Note(string title): _title(title)
{
}

Note::~Note()
{
}
