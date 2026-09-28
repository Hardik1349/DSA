#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;
};

void insertFront(Node*& head, int token) {
    Node* newNode = new Node();
    newNode->token = token;
    newNode->next = head;
    head = newNode;
}

void insertEnd(Node*& head, int token) {
    Node* newNode = new Node();
    newNode->token = token;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node*& head, int token, int position) {

    if (position == 1) {
        insertFront(head, token);
        return;
    }
    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position. Patient not inserted." << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->token = token;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->token << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    Node* head = NULL;

    insertFront(head, 101);
    cout << "After adding critical patient: ";
    display(head);

    insertEnd(head, 102);
    cout << "After adding routine patient: ";
    display(head);

    insertEnd(head, 103);
    cout << "After adding routine patient: ";
    display(head);

    insertAtPosition(head, 150, 2);
    cout << "After inserting priority patient at position 2: ";
    display(head);

    insertAtPosition(head, 175, 4);
    cout << "After inserting priority patient at position 4: ";
    display(head);

    insertAtPosition(head, 200, 10);
    cout << "After trying position 10: ";
    display(head);

    return 0;
}