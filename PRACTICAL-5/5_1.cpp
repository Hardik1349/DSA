#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
};

void insertBeginning(Node*& head, Node*& tail, string song)
{
    Node* newNode = new Node;
    newNode->song = song;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    else
    {
        tail = newNode;
    }
    head = newNode;
}

void insertEnd(Node*& head, Node*& tail, string song)
{
    Node* newNode = new Node;
    newNode->song = song;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail != NULL)
    {
        tail->next = newNode;
    }
    else
    {
        head = newNode;
    }
    tail = newNode;
}

void insertAfter(Node*& head, Node*& tail, string givenSong, string newSong)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->song == givenSong)
        {
            break;
        }
               temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Song not found!" << endl;
        return;
    }
    Node* newNode = new Node;
    newNode->song = newSong;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    if (newNode->next != NULL)
    {
        newNode->next->prev = newNode;
    }
    else
    {
        tail = newNode;
    }
}
void deleteFirst(Node*& head, Node*& tail)
{
    if (head == NULL)
    {
        cout << "Playlist is empty!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    else
    {
        tail = NULL;
    }
    delete temp;
}