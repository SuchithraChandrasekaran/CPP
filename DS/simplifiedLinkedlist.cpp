#include <iostream>
using namespace std;

// Define the Node structure
struct Node 
{
    int data;         // Data part
    Node* next;       // Pointer to the next node
};

// Function to print the linked list
void printList(Node* head) 
{
    while (head != NULL) 
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() 
{
    // Create nodes
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Assign data and link nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Print original list
    cout << "Original Linked List: ";
    printList(head);

    return 0;
}
/*
Walkthrough
1. Initial Call: Calling printList(head), where head points to the node with data 1.
2. Traversal:
   i.    The function prints 1 (data of the first node).
   ii.   It then moves to the next node (head->next), which contains 2.
   iii.  This process continues until it reaches NULL, indicating the end of the list.
   
Output: The function prints 1 -> 2 -> 3 -> NULL, showing all nodes in the list.
*/
