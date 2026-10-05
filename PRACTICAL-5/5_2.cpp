#include <iostream>
using namespace std;

struct SNode {
    int student;
    SNode* next;
};
void singlyInsert(SNode*& head, int student) {
    SNode* newNode = new SNode();
    newNode->student = student;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    SNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
void singlyDelete(SNode*& head, int student) {
    if (head == NULL) {
        cout << "Circle is empty." << endl;
        return;
    }
    if (head->student == student && head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    if (head->student == student) {
        SNode* last = head;
        while (last->next != head) {
            last = last->next;
        }
        SNode* temp = head;
        head = head->next;
        last->next = head;
        delete temp;
        return;
    }
    SNode* temp = head;
    while (temp->next != head &&
           temp->next->student != student) {
        temp = temp->next;
    }
    if (temp->next != head) {
        SNode* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }
    else {
        cout << "Student not found." << endl;
    }
}
void singlyDisplay(SNode* head) {
    if (head == NULL) {
        cout << "Circle is empty." << endl;
        return;
    }
    SNode* temp = head;
    do {
        cout << temp->student << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
struct DNode {
    int student;
    DNode* next;
    DNode* prev;
};
void doublyInsert(DNode*& head, int student) {
    DNode* newNode = new DNode();
    newNode->student = student;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }
    DNode* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}
void doublyDelete(DNode*& head, int student) {
    if (head == NULL) {
        cout << "Circle is empty." << endl;
        return;
    }
    DNode* temp = head;
    do {
        if (temp->student == student) {
            break;
        }
        temp = temp->next;
    } while (temp != head);
    if (temp->student != student) {
        cout << "Student not found." << endl;
        return;
    }
    if (temp->next == temp) {
        delete temp;
        head = NULL;
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    if (temp == head) {
        head = temp->next;
    }
    delete temp;
}
void doublyDisplay(DNode* head) {
    if (head == NULL) {
        cout << "Circle is empty." << endl;
        return;
    }
    DNode* temp = head;
    do {
        cout << temp->student << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    cout << "===== SINGLY CIRCULAR LINKED LIST =====" << endl;
    SNode* sHead = NULL;

    singlyInsert(sHead, 101);
    cout << "After 101 joins: ";
    singlyDisplay(sHead);

    singlyInsert(sHead, 102);
    cout << "After 102 joins: ";
    singlyDisplay(sHead);

    singlyInsert(sHead, 103);
    cout << "After 103 joins: ";
    singlyDisplay(sHead);

    singlyDelete(sHead, 102);
    cout << "After 102 leaves: ";
    singlyDisplay(sHead);

    singlyInsert(sHead, 104);
    cout << "After 104 joins: ";
    singlyDisplay(sHead);

    singlyDelete(sHead, 101);
    cout << "After 101 leaves: ";
    singlyDisplay(sHead);

    cout << endl;
    cout << "===== DOUBLY CIRCULAR LINKED LIST =====" << endl;
    DNode* dHead = NULL;

    doublyInsert(dHead, 101);
    cout << "After 101 joins: ";
    doublyDisplay(dHead);

    doublyInsert(dHead, 102);
    cout << "After 102 joins: ";
    doublyDisplay(dHead);

    doublyInsert(dHead, 103);
    cout << "After 103 joins: ";
    doublyDisplay(dHead);

    doublyDelete(dHead, 102);
    cout << "After 102 leaves: ";
    doublyDisplay(dHead);

    doublyInsert(dHead, 104);
    cout << "After 104 joins: ";
    doublyDisplay(dHead);

    doublyDelete(dHead, 101);
    cout << "After 101 leaves: ";
    doublyDisplay(dHead);

    return 0;
}