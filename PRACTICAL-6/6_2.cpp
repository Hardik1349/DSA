#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;
};

void visit(Node*& top, string& currentPage, string newPage) {

    Node* newNode = new Node();

    newNode->page = currentPage;
    newNode->next = top;

    top = newNode;

    currentPage = newPage;

    cout << "Visited: " << currentPage << endl;
    cout << "Current page: " << currentPage << endl;
}

void back(Node*& top, string& currentPage) {

    if (top == NULL) {
        cout << "Error: No previous page available." << endl;
        cout << "Current page: " << currentPage << endl;
        return;
    }

    Node* temp = top;

    currentPage = temp->page;

    top = top->next;

    delete temp;

    cout << "Back pressed." << endl;
    cout << "Current page: " << currentPage << endl;
}

int main() {

    Node* top = NULL;

    string currentPage = "Home";

    cout << "Current page: " << currentPage << endl;

    visit(top, currentPage, "Google");
    visit(top, currentPage, "YouTube");
    visit(top, currentPage, "Wikipedia");
    visit(top, currentPage, "GitHub");

    back(top, currentPage);
    back(top, currentPage);
    back(top, currentPage);
    back(top, currentPage);
    back(top, currentPage);

    return 0;
}