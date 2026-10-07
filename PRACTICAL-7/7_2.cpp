#include <iostream>
using namespace std;

struct Node {
    int patient;
    Node* next;
};

void arrive(Node*& front, Node*& rear, int patient) {

    Node* newNode = new Node();

    newNode->patient = patient;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Patient " << patient << " arrived." << endl;

    cout << "Current front patient: "
         << front->patient << endl;
}

void attend(Node*& front, Node*& rear) {

    if (front == NULL) {
        cout << "Error: No patients waiting." << endl;
        cout << "Current front patient: None" << endl;
        return;
    }

    cout << "Patient " << front->patient << " attended." << endl;

    Node* temp = front;

    front = front->next;

    delete temp;

    if (front == NULL) {
        rear = NULL;
        cout << "Current front patient: None" << endl;
    }
    else {
        cout << "Current front patient: "
             << front->patient << endl;
    }
}

int main() {

    Node* front = NULL;
    Node* rear = NULL;

    arrive(front, rear, 101);
    arrive(front, rear, 102);
    arrive(front, rear, 103);

    attend(front, rear);

    arrive(front, rear, 104);

    attend(front, rear);
    attend(front, rear);
    attend(front, rear);

    attend(front, rear);

    return 0;
}