#include<iostream>
#include<string>
using namespace std;


class Node
{
    public:
        int id;
        string name;
        double salary;
        Node* next;
};

int main()
{
    Node* head = NULL;
    Node* temp = NULL;
    Node* newnode = NULL; 
    int n;
    
    
    cout << " Enter number of employees: ";
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        newnode = new Node(); 
        
        cout << " \nEnter ID: "; 
        cin >> newnode->id;
        cout << " \nEnter Name: ";
        cin >> newnode->name;
        cout << " \nEnter Salary: ";
        cin >> newnode->salary;
        
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
    
    
    cout << "\n--- Linked List ---\n";
    temp = head;
    while(temp != NULL)
    {
        cout << "[" << temp->id << ", " << temp->name << ", $" << temp->salary << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
    
    
    int search_id;
    cout << "\n Enter ID to search: ";
    cin >> search_id;
    
    temp = head;
    bool found = false;
    while(temp != NULL)
    {
        if(temp->id == search_id)
        {
            cout << " Found! Name: " << temp->name << " | Salary: $" << temp->salary << "\n";
            found = true;
            break;
        }
        temp = temp->next;
    }
    if(!found) cout << " Employee not found.\n";

   
    int delete_id;
    cout << "\n Enter ID to delete: ";
    cin >> delete_id;
    
    temp = head;
    Node* prev = NULL;
    

    while(temp != NULL && temp->id != delete_id)
    {
        prev = temp;       
        temp = temp->next; 
    }
    
    if(temp == NULL)
    {
        cout << " ID not found. No deletion made.\n";
    }
    else
    {
       
        if(temp == head)
        {
            head = head->next;
        }
        
        else
        {
            prev->next = temp->next;
        }
        delete temp; 
        cout << " Deleted successfully!\n";
    }
    
    
    cout << "\n--- Updated Linked List ---\n";
    temp = head;
    while(temp != NULL)
    {
        cout << "[" << temp->id << ", " << temp->name << ", $" << temp->salary << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
    
    return 0;
}

