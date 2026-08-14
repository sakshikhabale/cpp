#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

int main()
{
    
    Node* head = NULL;
    Node* temp = NULL;
    Node* newnode = NULL; 
    int n, value;
    
    cout << " Enter number of nodes :";
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        
        newnode = new Node(); 
        
        cout << " Enter Data :"; 
        cin >> value;
        
        
        
        newnode->data = value;
        newnode->next = NULL;
        
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;    
        }
        else 
        {
            temp->next = newnode;
            temp = newnode;    
        }
    }
    
    cout << " Linklist : ";
    temp = head;
    
   
    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    
    return 0;
}

