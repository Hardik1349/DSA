#include <iostream>
using namespace std;

#define SIZE 10

struct Node {
    int bookCode;
    Node* next;
};

void insertBook(Node* shelf[], int code) {

    int index = code % 10;

    Node* newNode = new Node();

    newNode->bookCode = code;
    newNode->next = NULL;

    if (shelf[index] == NULL) {
        shelf[index] = newNode;
    }
    else {
        // Go to the end of the shelf
        Node* temp = shelf[index];

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void display(Node* shelf[]) {

    for (int i = 0; i < SIZE; i++) {

        cout << "Shelf " << i << ": ";

        Node* temp = shelf[i];

        if (temp == NULL) {
            cout << "Empty";
        }

        while (temp != NULL) {
            cout << temp->bookCode << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}

int main() {

    Node* shelf[SIZE];

    for (int i = 0; i < SIZE; i++) {
        shelf[i] = NULL;
    }

    int n;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int code;

        cout << "Enter book code: ";
        cin >> code;

        insertBook(shelf, code);
    }

    cout << endl;
    cout << "Final Shelf Contents:" << endl;

    display(shelf);

    return 0;
}