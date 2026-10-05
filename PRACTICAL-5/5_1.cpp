#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
};

void insertBeginning(Node*& head, string song) {
    Node* newNode = new Node();

    newNode->song = song;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void insertEnd(Node*& head, string song) {
    Node* newNode = new Node();

    newNode->song = song;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    newNode->prev = temp;
    temp->next = newNode;
}

void insertAfter(Node*& head, string oldSong, string newSong) {
    Node* temp = head;

    while (temp != NULL && temp->song != oldSong) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Song not found." << endl;
        return;
    }

    Node* newNode = new Node();

    newNode->song = newSong;

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void removeFirst(Node*& head) {
    if (head == NULL) {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
}

int countSongs(Node* head) {
    int count = 0;

    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->song << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    Node* head = NULL;

    insertBeginning(head, "Song A");
    cout << "After adding Song A at beginning: ";
    display(head);

    insertEnd(head, "Song B");
    cout << "After adding Song B at end: ";
    display(head);

    insertEnd(head, "Song C");
    cout << "After adding Song C at end: ";
    display(head);

    insertAfter(head, "Song B", "Song X");
    cout << "After inserting Song X after Song B: ";
    display(head);

    cout << "Total songs: " << countSongs(head) << endl;

    removeFirst(head);
    cout << "After removing first song: ";
    display(head);

    insertAfter(head, "Song Z", "Song Y");

    return 0;
}