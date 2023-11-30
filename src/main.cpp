#include <iostream>
#include "textNote.hpp"

int main() {
    TextNote* tx = new TextNote("a note", 1, "this is the content"); 
    tx->print();
    tx->append("appppppend");
    tx->print();
    tx->set("asdf");
    tx->print();
    return 0;
}
 