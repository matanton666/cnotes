#include "note.hpp"
#include "listNote.hpp"
#include "textNote.hpp"
#include "Folder.hpp"

const int OPTION = 2;

int main(int argc, char* argv[]) {
    TextNote* tx = new TextNote("note");
    {
        Folder f("test");
        f.append(tx);

        cout << f.get(0)->getId();
    }

    return 0;
}
 