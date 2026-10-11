#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorder(Node* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

void preorder(Node* root) {

    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
}

void postorder(Node* root) {

    if (root == NULL) {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    cout << root->data << " ";
}

void levelOrder(Node* root) {

    if (root == NULL) {
        return;
    }

    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {

        Node* temp = q.front();

        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL) {
            q.push(temp->left);
        }

        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

int main() {

    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->right = createNode(6);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Level Order: ";
    levelOrder(root);
    cout << endl;

    return 0;
}