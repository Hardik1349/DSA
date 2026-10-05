#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

void push(int tray) {

    if (top == MAX - 1) {
        cout << "Error: Stack is full. Cannot place tray "
             << tray << endl;
        return;
    }

    top++;
    stack[top] = tray;

    cout << "Tray " << tray << " placed." << endl;
    cout << "Current top tray: " << stack[top] << endl;
}

void pop() {

    if (top == -1) {
        cout << "Error: Stack is empty. Cannot take a tray."
             << endl;
        return;
    }

    cout << "Tray " << stack[top] << " taken." << endl;

    top--;

    if (top == -1) {
        cout << "Current top tray: None" << endl;
    }
    else {
        cout << "Current top tray: " << stack[top] << endl;
    }
}

int main() {

    push(101);
    push(102);
    push(103);

    pop();

    push(104);
    push(105);
    push(106);

    pop();
    pop();
    pop();
    pop();
    pop();

    return 0;
}