#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;
};

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

void deleteByValue(Node*& head, int token) {

    if (head == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }

    if (head->token == token) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->token != token) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Patient token not found." << endl;
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;
}

void displayForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->token << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayReverse(Node* head) {
    if (head == NULL) {
        return;
    }
    displayReverse(head->next);
    cout << head->token << " ";
}

int main() {

    Node* head = NULL;
    insertEnd(head, 101);
    insertEnd(head, 102);
    insertEnd(head, 103);
    insertEnd(head, 104);
    insertEnd(head, 105);
    cout << "Queue from front to back: ";
    displayForward(head);
    cout << "\nDeleting patient token 103..." << endl;
    deleteByValue(head, 103);
    cout << "Queue after deletion: ";
    displayForward(head);
    cout << "\nForward traversal: ";
    displayForward(head);
    cout << "Reverse printing: ";
    displayReverse(head);
    cout << endl;
    return 0;
}