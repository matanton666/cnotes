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
    Note(title)
{
    set(list);
}

ListNote::ListNote(string title) :
    Note(title)
{
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
void ListNote::append(string entrie)
{
    _list.push_back(entrie);
}

void ListNote::set(vector<string> list)
{
    _list.clear();
    _list = list;
}
