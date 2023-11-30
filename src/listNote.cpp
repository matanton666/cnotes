#include "include/listNote.hpp"

void ListNote::printList() const
{
    for (auto entrie : _list) 
    {
        cout << "\t[+] " << entrie << "\n";
    }
    
}

ListNote::ListNote(string title, unsigned int id, vector<string> list) : 
    Note(title, id)
{
    set(list);
}

ListNote::ListNote(string title, unsigned int id) :
    Note(title, id)
{
    _list = new vector<string>();
}

ListNote::~ListNote()
{
}

void ListNote::print() const
{
    cout << getId() << ") " << getTitle() << "\n";
    printList();
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
