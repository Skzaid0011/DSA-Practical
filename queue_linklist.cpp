#include <iostream>
using namespace std;
// Node class to create a new node
class node
{
public:
    int data;
    node *next;
// Constructor to initialize node
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
// Queue class using linked list
class queue
{
private:
    node *front;  // Points to the first node
    node *rear;   // Points to the last node

public:
    queue()    // Constructor to initialize an empty queue
    {
        front = rear = NULL;
    }
 // Function to check whether queue is empty
    int empty(void)
    {
        if (front == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
 // Function to return the front element
    int peek(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        return front->data;
    }
// Function to insert an element at the rear
    void enqueue(int x)
    {
        node *p = new node(x);

        if (front == NULL)
        {
            front = p;
            rear = p;
        }
        else
        {
            rear->next = p;
            rear = p;
        }
    }
 // Function to remove an element from the front
    int dequeue(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        int x = front->data;
        node *p = front;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete p;

        return x;
    }
// Function to display all queue elements
    void display(void)
    {
        node *q = front;

        cout << "\nQueue elements: ";

        while (q != NULL)
        {
            cout << "\t" << q->data;
            q = q->next;
        }
    }
};

int main()
{
    int x;
    queue q;
 // Insert elements into the queue
    q.enqueue(27);
    q.enqueue(34);
    q.enqueue(42);
    q.enqueue(58);
    q.enqueue(65);
    q.enqueue(70);

    q.display();
// Remove the front element if queue is not empty
    if (!q.empty())
    {
        x = q.dequeue();
        cout << "\nRemoved: " << x;
    }

    q.display();   // Display remaining elements

    x = q.peek();
    cout << "\nFront element is: " << x;

    return 0;
}

//output
PS D:\Zaid.46> cd "d:\Zaid.46\" ; if ($?) { g++ queue_linklist.cpp -o queue_linklist } ; if ($?) { .\queue_linklist }

Queue elements:         27      34      42      58      65      70
Removed: 27
Queue elements:         34      42      58      65      70
Front element is: 34
