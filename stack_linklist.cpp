#include <iostream>
using namespace std;
// Node class to create a new node
class node {
public:
    int data;
    node *next;
// Constructor to initialize node
    node(int x) {
        data = x;
        next = NULL;
    }
};
// Stack class using linked list
class stack {
private:
    node *top;   // Points to the top node

public:
// Constructor to initialize an empty stack
    stack() {
        top = NULL;
    }
// Function to check whether stack is empty
    int empty() {
        if (top == NULL) {
            return 1;
        } else {
            return 0;
        }
    }
// Function to insert an element into the stack
    void push(int x) {
        node *p = new node(x);
        p->next = top;
        top = p;
    }
 // Function to remove the top element
    int pop(void) {
        int x = top->data;
        node *p = top;
        top = top->next;
        delete p;
        return x;
    }
// Function to return the top element
    int peek() {
        return top->data;
    }
// Function to display stack elements
    void display() {
        node *q = top;
        while (q != NULL) {
            cout << endl << q->data;
            q = q->next;
        }
    }
};

int main() {
    int x;
    stack s;  // Create stack object
 // Insert elements into the stack
    s.push(99);
    s.push(81);
    s.push(33);
    s.push(58);
    s.push(10);
    s.push(20);
    
    s.display();   // Display stack elements
// Remove the top element if stack is not empty
    if (!s.empty()) {
        x = s.pop();
        cout << endl << "Removed" << x;
    }
    
    s.display();

    x = s.peek();
    cout << endl << "Top Element is:" << x;

    return 0;
}

//Output
PS D:\Zaid.46> cd "d:\Zaid.46\" ; if ($?) { g++ stack_linklist.cpp -o stack_linklist } ; if ($?) { .\stack_linklist }

20
10
58
33
81
99
Removed20
10
58
33
81
99
Top Element is:10
