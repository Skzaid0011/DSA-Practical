#include <iostream>
using namespace std;

const int MAX = 5;  // Maximum size of stack
// Stack class using array
class Stack
{
private:
    int a[MAX];
    int top;

public:
// Constructor to initialize an empty stack
    Stack()
    {
        top = -1;
    }
 // Function to insert an element into the stack
    void push(int x)
    {
        top++;
        a[top] = x;
    }
// Function to remove the top element
    int pop(void)
    {
        int x = a[top];
        top--;
        return x;
    }
 // Function to return the top element without removing it
    int peek(void)
    {
        return a[top];
    }
 // Function to check whether stack is full
    int full(void)
    {
        if (top == MAX - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // Function to check whether stack is empty
    int empty(void)
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
 // Function to display stack elements from top to bottom
    void display(void)
    {
        for (int i = top; i >= 0; i--)
        {
            cout << endl << a[i];
        }
    }
};

int main()
{
    int x;
    Stack s;
// Insert elements if stack is not full
    if (!s.full()) s.push(12);
    if (!s.full()) s.push(34);
    if (!s.full()) s.push(56);
    if (!s.full()) s.push(87);
    if (!s.full()) s.push(92);
    if (!s.full()) s.push(99);

    cout << "Stack elements:";
    s.display();   // Display stack elements
// Remove the top element if stack is not empty
    if (!s.empty())
    {
        x = s.pop();
        cout << endl << "Removed: " << x;
    }

    cout << endl << "Stack after pop:";
    s.display();

    if (!s.empty())
    {
        x = s.peek();
        cout << endl << "Top element is: " << x;
    }

    return 0;
}

//Output
PS D:\Zaid.46> cd "d:\Zaid.46\" ; if ($?) { g++ stack_array.cpp -o stack_array } ; if ($?) { .\stack_array }
Stack elements:
92
87
56
34
12
Removed: 92
Stack after pop:
87
56
34
12
Top element is: 87
