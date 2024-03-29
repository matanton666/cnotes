#include "include/textNote.hpp"


TextNote::TextNote(string title, string content) : 
    TextNote(title)
{
    _content = content;
}

TextNote::TextNote(string title) :
    Note(title)
{
    set("");
    _type = TEXT_NOTE;
}

TextNote::TextNote(const TextNote& other): Note(other.getTitle())
{
    _type = other._type;
    _content = other._content;
}


TextNote::~TextNote()
{
}

void TextNote::print() const
{
    printHead();
    cout << "\t" << _content << "\n";
}

void TextNote::printHead() const
{
    Note::printHead();
    cout << " | Text\n";
}

const unsigned int TextNote::getClassSize() const 
{
    return sizeof(*this);
}

json TextNote::serialize() const 
{
    json j;
    j["title"] = getTitle();
    j["type"] = _type;
    j["id"] = getId();
    j["content"] = _content;
    return j;
}


void TextNote::append(string newContent) 
{
    _content.append(newContent);
}

void TextNote::set(string newContent) 
{
    _content.clear();
    _content = newContent;
}