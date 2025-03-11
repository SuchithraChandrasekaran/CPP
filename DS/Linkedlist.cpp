/*
A linked list is a linear data structure in which elements (nodes) 
are connected using pointers. 
Each node contains two parts:

Data – The actual value stored in the node.
Pointer (or reference) – A link to the next node in the sequence.

Real-Time Examples of Linked Lists
-------------------------------
Music Playlist (Doubly Linked List) 
When playing songs in a music player, you can navigate next and previous.
A doubly linked list is used to maintain this list, allowing smooth navigation between songs.

Web Browser History (Doubly Linked List) 
When you click Back and Forward in a web browser, the pages are stored as nodes in a doubly linked list, allowing smooth traversal between visited web pages.

Text Editor (Undo/Redo) (Doubly Linked List or Stack with Linked List) 
Every edit is stored in a doubly linked list or a stack using a linked list structure.
Pressing Undo moves back in the list, and Redo moves forward.
*/

#include <iostream>
using namespace std;

// Definition of a Node in a singly linked list
struct Node 
{
    int data;     // Data part of the node
    Node* next;   // Pointer to the next node in the list

    // Constructor to initialize the node with data
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Class to manage the singly linked list
class LinkedList 
{
    private:
      Node* head; // Pointer to the first node

    public:
      // Constructor to initialize an empty list
      LinkedList() 
      {
          head = nullptr;
      }

    // Function to insert a node at the end
    void insertAtEnd(int data) 
    {
        Node* newNode = new Node(data);
        if (head == nullptr) 
        {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to delete a node by value
    void deleteNode(int value) 
    {
        if (head == nullptr) 
        {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        if (head->data == value) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != value) 
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) 
        {
            cout << "Value not found in list.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Function to display the linked list
    void display() 
    {
        if (head == nullptr) 
        {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor to free memory
    ~LinkedList() 
    {
        Node* temp;
        while (head != nullptr) 
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver function
int main() 
{
    LinkedList list;
    
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Linked List: ";
    list.display();

    cout << "Deleting 20...\n";
    list.deleteNode(20);
    
    cout << "Updated Linked List: ";
    list.display();

    return 0;
}
