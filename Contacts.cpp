#include <iostream>
#include "Contacts.h"
#include <cstring>
using namespace std;
void PrintContactByName(Book *book, char *name)
{
    Contact contact = getContactByName(book, name);
    cout << "Name:" << contact.name << endl;
    cout << "Phone:" << contact.phone << endl;
    cout << "Group: ";
    switch (contact.group)
    {
        case 1:
        {
            cout << "No_Group" << endl;
            break;
        }
        case 2:
        {
            cout << "Family" << endl;
            break;
        }
        case 3:
        {
            cout << "Friends" << endl;
            break;
        }
        case 4:
        {
            cout <<"Colleagues" << endl;
            break;
        }
        default:
        {
            cout << "ERROR" << endl;
        }
    }
}
void PrintContactByPhone(Book *book, char *phone)
{
    Contact contact = getContactByPhone(book, phone);
    cout << "Name:" << contact.name << endl;
    cout << "Phone:" << contact.phone << endl;
    cout << "Group: ";
    switch (contact.group)
    {
        case 1:
        {
            cout << "No_Group" << endl;
            break;
        }
        case 2:
        {
            cout << "Family" << endl;
            break;
        }
        case 3:
        {
            cout << "Friends" << endl;
            break;
        }
        case 4:
        {
            cout <<"Colleagues" << endl;
        }
        default:
        {
            cout << "ERROR" << endl;
        }
    }
}
Book *CreateBook(size_t size)
{
    auto* book = new Book;
    auto* data = new Contact[size];
    book->data = data;
    book->size = size;
}

void deleteBook(Book *book)
{
    delete[] book->data;
    delete[] book;
}

void reserve(Book *book, size_t newCap)
{
    if (newCap > book->size)
    {
        Book* new_book = CreateBook(newCap);
        for (int i = 0; i < book->size; i++)
        {
            new_book->data[i] = book->data[i];
        }
        book->data = new_book->data;
        delete new_book;
        book->size = newCap;
    }

}

Contact getContactByName(Book *book, const char *name)
{
    for (int i = 0; i < book->size; i++)
    {
        if (strcmp(book->data[i].name, name) == 0)
            return book->data[i];
    }
}

Contact getContactByPhone(Book *book, const char *phone)
{
    for (int i = 0; i < book->size; i++)
    {
        if (strcmp(book->data[i].phone, phone) == 0)
            return book->data[i];
    }
}

int getIndex(Book *book, char* name)
{
    for (int i = 0; i < book->size; i++)
    {
        if (strcmp(book->data[i].name, name) == 0)
            return static_cast<size_t>(i);
    }
    return -1;
}

void CreateContact(Book *book)
{
    Contact contact{};
    reserve(book, book->size + 1);
    cout << "Write down name" << endl;
    char name[80];
    bool ifUsed = false;
    while (true)
    {
        cin >> name;
        for (int i = 0; i < book->size - 1; i++)
        {
            if (strcmp(name, book->data[i].name) == 0)
            {
                cout << "This name has been already used, please, print another name" << endl;
                ifUsed = true;
                break;
            }
        }
        if (ifUsed)
        {
            ifUsed = false;
            continue;
        }
        break;
    }
    for (int j = 0; j < 80; j++)
    {
        contact.name[j] = name[j];
    }
    cout << "Write down phone" << endl;
    cin >> contact.phone;
    cout << "Choose new group:" << endl;
    cout << "1) No group" << endl;
    cout << "2) Family" << endl;
    cout << "3) Friends" << endl;
    cout << "4) Colleagues" << endl;
    string group;
    while (true)
    {
        cin >> group;
        if (group == "1")
        {
            contact.group = NO_GROUP;
            break;
        }
        if (group == "2")
        {
            contact.group = FAMILY;
            break;
        }
        if (group == "3")
        {
            contact.group = FRIENDS;
            break;
        }
        if (group == "4")
        {
            contact.group = COLLEAGUES;
            break;
        }
        if (group != "1" && group != "2" && group != "3" && group != "4")
        {
            cout <<"Please, choose group correctly" << endl;
            continue;
        }
    }
    book->data[book->size - 1] = contact;
}

void DeleteContact(Book *book, char* name)
{
    int index = getIndex(book, name);
    if (index == -1)
    {
        cout << "Contact has not been found" << endl;
        return;
    }
    Book* new_book = CreateBook(book->size - 1);
    for (int i = 0; i < index; i++)
    {
        new_book->data[i] = book->data[i];
    }
    for (int i = index; i < book->size - 1; i++)
    {
        new_book->data[i] = book->data[i + 1];
    }
    book->data = new_book->data;
    book->size--;
    delete new_book;
}
void EditContact(Book *book, char* name) {
    int index = getIndex(book, name);
    if (index == -1)
    {
        cout << "Contact has not been found" << endl;
        return;
    }
    string answer;
    cout << "Do you want to change name? yes/no" << endl;
    cin >> answer;
    if (answer == "yes") {
        cout << "Write down new name" << endl;
        char new_name[80];
        bool ifUsed = false;
        while (true)
        {
            cin >> new_name;
            for (int i = 0; i < book->size; i++)
            {
                if (strcmp(new_name, book->data[i].name) == 0)
                {
                    cout << "This name has been already used, please, print another name" << endl;
                    ifUsed = true;
                    break;
                }
            }
            if (ifUsed)
            {
                ifUsed = false;
                continue;
            }
            break;
        }
        for (int i = 0; i < 80; i++) {
            book->data[index].name[i] = new_name[i];
        }
    }
    cout << "Do you want to change phone? yes/no" << endl;
    cin >> answer;
    if (answer == "yes")
    {
        cout << "Write down new phone" << endl;
        char new_phone[12];
        cin >> new_phone;
        for (int i = 0; i < 12; i++) {
            book->data[index].phone[i] = new_phone[i];
        }
    }
    cout << "Do you want to change group? yes/no" << endl;
    cin >> answer;
    if (answer == "yes") {
        cout << "Choose new group:" << endl;
        cout << "1) No group" << endl;
        cout << "2) Family" << endl;
        cout << "3) Friends" << endl;
        cout << "4) Colleagues" << endl;
        int group;
        cin >> group;
        book->data[index].group = group;
    }
}
void printPhone(Book *book, char* name)
{
    Contact contact = getContactByName(book, name);
    cout << "Phone:" << contact.phone << endl;
}
void Print (Book *book)
{
    cout << "What do you want to do?" << endl;
    cout << "1) Print contact by name" << endl;
    cout << "2) Print contact by phone" << endl;
    cout << "3) Print all contacts in group" << endl;
    cout << "4) Print all contacts" << endl;
    string answer;
    cin >> answer;
    if (answer == "1")
    {
        char name[80];
        cout << "Write down name" << endl;
        cin >> name;
        PrintContactByName(book, name);
    }
    if (answer == "2")
    {
        char phone[12];
        cout << "Write down phone" << endl;
        cin >> phone;
        PrintContactByPhone(book, phone);
    }
    if (answer == "3")
    {
        string group;
        cout << "Write down group" << endl;
        cout << "1) No group" << endl;
        cout << "2) Family" << endl;
        cout << "3) Friends" << endl;
        cout << "4) Colleagues" << endl;
        cin >> group;
        if (group == "1") {
            for (int i = 0; i < book->size; i++) {
                if (book->data[i].group == 1) {
                    PrintContactByName(book, book->data[i].name);
                }
            }
        }
        if (group == "2") {
            for (int i = 0; i < book->size; i++) {
                if (book->data[i].group == 2) {
                    PrintContactByName(book, book->data[i].name);
                }
            }
        }
        if (group == "3")
        {
            for (int i = 0; i < book->size; i++) {
                if (book->data[i].group == 3) {
                    PrintContactByName(book, book->data[i].name);
                }
            }
        }
        if (group == "4")
        {
            for (int i = 0; i < book->size; i++) {
                if (book->data[i].group == 4) {
                    PrintContactByName(book, book->data[i].name);
                }
            }
        }
    }
        if (answer == "4")
        {
            for (int i = 0; i < book->size; i++)
            {
                PrintContactByName(book, book->data[i].name);
            }
        }
}