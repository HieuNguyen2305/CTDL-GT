#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Tree {
    struct Node* root;
    Tree(int d) {
        root = new Node(d);
    }
};

void Trungto(Node* p) {
    if (p != nullptr) {
        Trungto(p->left);
        cout << p->data << " ";
        Trungto(p->right);
    }
}

void Tiento(Node* p) {
    if (p != nullptr) {
        cout << p->data << " ";
        Tiento(p->left);
        Tiento(p->right);
    }
}

void Hauto(Node* p) {
    if (p != nullptr) {
        Hauto(p->left);
        Hauto(p->right);
        cout << p->data << " ";
    }
}

int main() {
    Tree T(5);
    T.root->left = new Node(6);
    T.root->right = new Node(7);
    T.root->left->left = new Node(8);
    T.root->left->right= new Node(9);

    cout << "Duyệt trung tố: ";
    Trungto(T.root);
    cout << endl;

    cout << "Duyệt tiền tố: ";
    Tiento(T.root);
    cout << endl;

    cout << "Duyệt hậu tố: ";
    Hauto(T.root);
    cout << endl;

    return 0;
}
