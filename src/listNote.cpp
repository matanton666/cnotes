#include "include/listNote.hpp"
#include "listNote.hpp"

void ListNote::printList() const
{
    for (auto entrie : _list) 
    {
        cout << "\t[+] " << entrie << "\n";
    }
    
}

ListNote::ListNote(string title, vector<string> list) : 
    ListNote(title)
{
    set(list);
}

ListNote::ListNote(string title) :
    Note(title)
{
    _type = LIST_NOTE;
}

ListNote::~ListNote()
{
}

void ListNote::print() const
{
    printHead();
    printList();
}

void ListNote::printHead() const
{
    Note::printHead();
    cout << " | List\n";
}

const unsigned int ListNote::getClassSize() const 
{
    return sizeof(*this);
}

json ListNote::serialize() const 
{
    json j;
    j["title"] = getTitle();
    j["type"] = _type;
    j["id"] = getId();

    j["content"];
    for (int i = 0; i < _list.size(); i++)
    {
        j["content"].push_back(_list[i]);
    }
    
    return j;
}

void ListNote::append(string entrie)
{
    _list.push_back(entrie);
}

void ListNote::set(vector<string> list)
{
    _list.clear();
    _list = list;
}
