#include "include/note.hpp"
#include "note.hpp"

unsigned int Note::_idCount;

unsigned int Note::generateId()
{
    return ++_idCount;
}

Note::Note(string title) : _title(title), _id(generateId()), _type(ABSTRACT_NOTE)
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
const NoteType Note::getNoteType() const
{
    return _type;
}
const unsigned int Note::getClassSize() const
{
    return sizeof(*this);
}
void Note::printHead() const
{
    cout << getId() << ") " << getTitle();
}
