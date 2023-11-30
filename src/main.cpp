#include <iostream>
#include "textNote.hpp"
#include "listNote.hpp"

int main() {
    TextNote* tx = new TextNote("a note", 1, "this is the content"); 
    tx->print();
    tx->append("appppppend");
    tx->print();
    tx->set("asdf");
    tx->print();

    ListNote* lx = new ListNote("shopping", 2);
    lx->print();
    lx->append("cucumber");
    lx->append("apple");
    lx->print();
    

    return 0;
}
 