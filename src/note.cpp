#include "note.hpp"

Note::Note(string title, unsigned int id): _title(title), _id(id)
{
}

Note::~Note()
{
}

string Note::getTitle() const
{
    return _title;
}

unsigned int Note::getId() const
{
    return _id;
}
