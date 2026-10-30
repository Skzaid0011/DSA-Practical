#include <iostream>
using namespace std;

// Node class to store data and pointers
class Node {
public:
    int data;
    Node* prev;  // Points to previous node
    Node* next;  // Points to next node

 // Constructor to initialize a new node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Class to implement Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;

public:
 // Constructor to initialize an empty list
    DoublyLinkedList() {
        head = nullptr;
    }

// Function to insert a node at the end
    void insert(int val) {
        Node* p = new Node(val); // p is used for new node
        if (head == nullptr) {
            head = p;
        } else {
            Node* q = head; // q is used for traversal
            while (q->next != nullptr) {
                q = q->next;
            }
            q->next = p;
            p->prev = q;
        }
    }

    // Function to delete a node by value
    void remove(int val) {
        Node *p,*q;
               q = head;
 // Delete the first node
                if (q->data == val) {
                p = head;
                head=head->next;
                head->prev=nullptr;
                delete p;
                return;
                }
         // Search and delete the required node       
                while (q->next != NULL) {
            if (q->next->data == val) {
                p = q->next;
                q->next = p->next;
                p->next->prev=q;
                delete p;
                return;
            }
            q = q->next;
        }
       
  

        cout << "Value " << val << " not found in the list.\n";
    }

// Function to display list in forward direction
    void displayForward() {
        Node* q = head;
        cout << "Forward: ";
        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->next;
        }
        cout << "NULL\n";
    }

   // Function to display list in backward direction  
    void displayBackward() {
        Node* q = head;
        if (q == nullptr) {
            cout << "Backward: NULL\n";
            return;
        }

        
        while (q->next != nullptr) {
            q = q->next;
        }

        cout << "Backward: ";
        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->prev;
        }
        cout << "NULL\n";
    }
};


int main() {
    DoublyLinkedList list;
// Insert elements into the list
    list.insert(10);
    list.insert(20);
    list.insert(30);
    
    list.displayForward();   // Display in forward direction 
    list.displayBackward();  // Display in backward direction
 

    list.remove(20);  // Delete node containing 20
   
    list.displayForward();   // Display updated list
    list.displayBackward();  // Display updated list in reverse

    return 0;
}

//Output
PS D:\Zaid.46> cd "d:\Zaid.46\" ; if ($?) { g++ double_linklist.cpp -o double_linklist } ; if ($?) { .\double_linklist }
Forward: 10 <-> 20 <-> 30 <-> NULL
Backward: 30 <-> 20 <-> 10 <-> NULL
Forward: 10 <-> 30 <-> NULL
Backward: 30 <-> 10 <-> NULL
