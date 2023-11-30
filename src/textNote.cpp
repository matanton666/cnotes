#include "include/textNote.hpp"


TextNote::TextNote(string title, string content) : 
    Note(title), _content(content)
{
}

TextNote::TextNote(string title) :
    Note(title)
{
    set("");
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


void TextNote::append(string newContent) 
{
    _content.append(newContent);
}

void TextNote::set(string newContent) 
{
    _content.clear();
    _content = newContent;
}