#include <iostream>
using namespace std;

struct Node {
    int student;
    Node* next;
};
void insertStudent(Node*& head, int student) {
    Node* newNode = new Node();
    newNode->student = student;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
void deleteStudent(Node*& head, int student) {
    if (head == NULL) {
        return;
    }
    if (head->student == student && head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    if (head->student == student) {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        Node* temp = head;
        head = head->next;
        last->next = head;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != head && temp->next->student != student) {
        temp = temp->next;
    }
    if (temp->next != head) {
        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }
}

void display(Node* head) {
    if (head == NULL) {
        cout << "Circle is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->student << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {

    Node* head = NULL;
    cout << "Singly Circular Linked List\n\n";
    insertStudent(head, 101);
    cout << "After joining 101: ";
    display(head);
    insertStudent(head, 102);
    cout << "After joining 102: ";
    display(head);
    insertStudent(head, 103);
    cout << "After joining 103: ";
    display(head);
    deleteStudent(head, 102);
    cout << "After 102 leaves: ";
    display(head);
    insertStudent(head, 104);
    cout << "After joining 104: ";
    display(head);
    deleteStudent(head, 101);
    cout << "After 101 leaves: ";
    display(head);
    return 0;
}