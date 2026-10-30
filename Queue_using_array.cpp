#include <iostream>
using namespace std;

const int MAX = 5; // Maximum size of the queue
// Class to implement Queue
class queue
{
private:
    int a[MAX];  // Array to store queue elements
    int front;   // Points to the first element
    int rear;    // Points to the last element

public:
 // Constructor: Initializes an empty queue
    queue()
    {
        front = -1;
        rear = -1;
    }
  // Function to check whether the queue is empty
    int empty(void)
    {
        if (front == -1 && rear == -1)
        {
            return 1; // Queue is empty
        }
        else
        {
            return 0;
        }
    }
// Function to check whether the queue is full
    int full(void)
    {
        if (rear == MAX - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
// Function to insert an element into the queue
    void enqueue(int x)
    {
        if (full())
        {
            cout << "\nQueue is full";
            return;
        }

        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }

        a[rear] = x;
    }
 // Function to remove an element from the queue
    int dequeue(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        int x = a[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }

        return x;
    }
 // Function to display the front element
    int peek(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return -1;
        }

        return a[front];
    }

    void display(void)
    {
        if (empty())
        {
            cout << "\nQueue is empty";
            return;
        }

        cout << "\nQueue elements:";
        for (int i = front; i <= rear; i++)
        {
            cout << "\t" << a[i];
        }
    }
};

int main()
{
    int x;
    queue q;
// Insert five elements into the queue
    q.enqueue(95);
    q.enqueue(90);
    q.enqueue(20);
    q.enqueue(46);
    q.enqueue(26);

    q.display();

    if (!q.empty())
    {
        x = q.dequeue();
        cout << "\nRemoved: " << x;
    }

    q.display();

    x = q.peek();
    cout << "\nFront element is: " << x;

    return 0;
}
