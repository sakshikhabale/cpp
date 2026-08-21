#include <iostream>
using namespace std;

class arraystack
{
    string a[10];
    int top;

public:
    arraystack()
    {
        top = -1;
    }

    void push(string page)
    {
        if (top < 9)
            a[++top] = page;
        else
            cout << "Stack Overflow\n";
    }

    void pop()
    {
        if (top >= 0)
            cout << "BACK: " << a[top--] << endl;
        else
            cout << "No History\n";
    }

    void show()
    {
        for (int i = top; i >= 0; i--)
            cout << a[i] << " ";

        cout << endl;
    }
};

int main()
{
    arraystack a;

    a.push("google");
    a.push("youtube");
    a.push("github");

    cout << "History: ";
    a.show();

    a.pop();

    cout << "After Back: ";
    a.show();

    return 0;
}
