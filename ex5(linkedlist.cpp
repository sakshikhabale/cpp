#include <iostream>
using namespace std;

struct node
{
    string page;
    node* next;
};

class linkedstack
{
    node* top;

public:
    linkedstack()
    {
        top = NULL;
    }

    void push(string page)
    {
        node* n = new node{page, top}
		top = n;
    }

    void pop()
    {
        if (top)
        {
            cout << "BACK: " << top->page << endl;

            node* temp = top;
            top = top->next;

            delete temp;
        }
        else
        {
            cout << "No History\n";
        }
    }

    void show()
    {
        for (node* p = top; p != NULL; p = p->next)
            cout << p->page << " ";

        cout << endl;
    }
};

int main()
{
    linkedstack l;

    l.push("google");
    l.push("youtube");
    l.push("github");

    cout << "History: ";
    l.show();

    l.pop();

    cout << "After Back: ";
    l.show();

    return 0;
}
