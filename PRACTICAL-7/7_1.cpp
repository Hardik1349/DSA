#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];

int front = -1;
int rear = -1;

void enqueue(int token) {

    if ((rear + 1) % MAX == front) {
        cout << "Error: Queue is full. Token cannot be issued."
             << endl;
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = token;

    cout << "Token " << token << " joined." << endl;

    cout << "Current front token: "
         << queue[front] << endl;
}

void dequeue() {

    if (front == -1) {
        cout << "Error: Queue is empty. Nobody can be served."
             << endl;
        return;
    }

    cout << "Token " << queue[front] << " served." << endl;

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }

    if (front == -1) {
        cout << "Current front token: None" << endl;
    }
    else {
        cout << "Current front token: "
             << queue[front] << endl;
    }
}

int main() {

    enqueue(101);
    enqueue(102);
    enqueue(103);

    dequeue();

    enqueue(104);
    enqueue(105);
    enqueue(106);

    dequeue();
    dequeue();

    enqueue(107);
    enqueue(108);

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}