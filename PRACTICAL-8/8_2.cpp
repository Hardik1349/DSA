#include <iostream>
using namespace std;

struct Node {
    int code;
    Node* left;
    Node* right;
};

Node* createNode(int code) {
    Node* newNode = new Node();

    newNode->code = code;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insert(Node* root, int code) {

    if (root == NULL) {
        return createNode(code);
    }

    if (code < root->code) {
        root->left = insert(root->left, code);
    }

    else if (code > root->code) {
        root->right = insert(root->right, code);
    }

    return root;
}

void inorder(Node* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->code << " ";

    inorder(root->right);
}

int main() {

    Node* root = NULL;

    int codes[] = {50, 30, 70, 20, 40, 60, 80};

    int n = 7;

    for (int i = 0; i < n; i++) {
        root = insert(root, codes[i]);
    }

    cout << "Inorder sequence: ";
    inorder(root);

    return 0;
}