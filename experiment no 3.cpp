#include <iostream>
#include <cstring>
using namespace std;

struct Book
{
    int id;
    char title[50];
    Book *next; 
};

Book *head = NULL;
Book *current = NULL;

void addBook()
{
    Book *newBook, *temp;

    newBook = new Book;

    cout << "\nEnter Book ID: ";
    cin >> newBook->id;

    cout << "Enter Book Title: ";
    cin >> newBook->title;

    newBook->next = NULL;

    if (head == NULL)
    {
        head = newBook;
        newBook->next = head;
        current = head;
    }
    else
    {
        temp = head;

       
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newBook;
        newBook->next = head; 
    }

    cout << "Book added successfully!\n";
}



void displayBooks()
{
    Book *temp;

    if (head == NULL)
    {
        cout << "\nNo books available!\n";
        return;
    }

    temp = head;

    cout << "\n----- Catalog Inventory -----\n";

    do
    {
        cout << "Book ID: " << temp->id
             << "  Title: " << temp->title << endl;

        temp = temp->next;

    } while (temp != head);
}


void nextBook()
{
    if (current == NULL)
    {
        cout << "\nNo books available!\n";
        return;
    }

    current = current->next;

    cout << "\nCurrent Book Selected: "
         << current->title << endl;
}



void crossReferenceBooks()
{
    Book *first;
    Book *second;

    if (head == NULL)
    {
        cout << "\nNo books available for checks!\n";
        return;
    }

    first = head;

    cout << "\n===== GENRE ACCORDANCE CHECKS =====\n";

    do
    {
        second = first->next;

        while (second != head)
        {
            cout << "Compare: [" << first->title << "] with [" << second->title << "]" << endl;
            second = second->next;
        }

        first = first->next;

    } while (first != head);
}



int main()
{
    int choice;

    do
    {
        cout << "\n===== CAMPUS BOOK CATALOG SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Catalog\n";
        cout << "3. Select Next Book\n";
        cout << "4. Generate Cross Reference Map\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                nextBook();
                break;

            case 4:
                crossReferenceBooks();
                break;

            case 5:
                cout << "\nCatalog System closed.\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

