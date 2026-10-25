#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

class stack {
private:
    node *top;

public:
    stack() {
        top = NULL;
    }

    int empty() {
        if (top == NULL) {
            return 1;
        } else {
            return 0;
        }
    }

    void push(int x) {
        node *p = new node(x);
        p->next = top;
        top = p;
    }

    int pop(void) {
        int x = top->data;
        node *p = top;
        top = top->next;
        delete p;
        return x;
    }

    int peek() {
        return top->data;
    }

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
    stack s;

    s.push(99);
    s.push(81);
    s.push(33);
    s.push(58);
    s.push(10);
    s.push(20);
    
    s.display();

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