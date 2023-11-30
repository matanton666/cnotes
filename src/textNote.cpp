#include "include/textNote.hpp"


TextNote::TextNote(string title, unsigned int id, string content) : 
    Note(title, id), _content(content)
{
}

TextNote::TextNote(string title, unsigned int id) :
    Note(title, id)
{
    _content = "";
}
TextNote::~TextNote()
{
}

void TextNote::print() const
{
    cout << getId() << ") " << getTitle() << "\n\t" << _content << "\n";
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