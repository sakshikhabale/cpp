#include <iostream>
using namespace std;

// Array Stack
class ArrayStack {
    string a[10];
    int top;

public:
    void push(string page) {
        if (top < 9) a[++top] = page;
    }

    void pop() {
        if (top >= 0)
            cout << "Back: " << a[top--] << endl;
        else
            cout << "No history\n";
    }

    void show() {
        for (int i = top; i >= 0; i--)
            cout << a[i] << " ";
        cout << endl;
    }
};

// Linked List Stack
struct Node {
    string page;
    Node* next;
};

class LinkedStack {
    Node* top = NULL;

public:
    void push(string page) {
        Node* n = new Node{page, top}
        top = n;
    }

    void pop() {
        if (top) {
            cout << "Back: " << top->page << endl;
            Node* temp = top;
            top = top->next;
            delete temp;
        } else
            cout << "No history\n";
    }

    void show() {
        for (Node* p = top; p; p = p->next)
            cout << p->page << " ";
        cout << endl;
    }
};

int main() {
    ArrayStack a;
    LinkedStack l;

    // Array
    a.push("Google");
    a.push("YouTube");
    a.push("GitHub");
    a.show();
    a.pop();

    // Linked List
    l.push("Google");
    l.push("YouTube");
    l.push("GitHub");
    l.show();
    l.pop();

    return 0;
}
