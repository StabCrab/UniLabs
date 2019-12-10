//
// Created by trykr on 21.11.2019.
//

#include "Contacts.h"
#include <fstream>
using namespace std;
int main()
{
    Book *book = CreateBook(0);
    string answer;
    while (true)
    {
        cout << "What do you want to do?" << endl;
        cout << "1) Create new contact" << endl;
        cout << "2) Delete contact" << endl;
        cout << "3) Edit contact" << endl;
        cout << "4) Show contact(s)" << endl;
        cout << "5) Exit" << endl;
        cin >> answer;
            if (answer == "1")
            {
                CreateContact(book);
                continue;
            }
            if (answer == "2")
            {
                cout << "Write down name of the contact, which need to be deleted" << endl;
                char name[80];
                cin >> name;
                DeleteContact(book, name);
                continue;
            }
            if (answer == "3")
            {
                cout << "Write down name of the contact, which needs to be edited" << endl;
                char name[80];
                cin >> name;
                EditContact(book, name);
                continue;
            }
            if (answer == "4")
            {
                Print(book);
                continue;
            }
            if (answer == "5")
            {
                deleteBook(book);
                return 0;
            }
    }
}