#include <iostream>
using namespace std;
#include <math.h>
struct Node {
    int data;
    Node* left;
    Node* right;

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

void vunDong(Node* root) {
    if (root == NULL) return;

    // Vun đống con trái
    vunDong(root->left);

    // Vun đống con phải
    vunDong(root->right);

    // Kiểm tra và đổi vị trí nếu cần thiết
    if (root->left != NULL && root->left->data > root->data) {
        std::swap(root->data, root->left->data);
        vunDong(root->left);
    }
    if (root->right != NULL && root->right->data > root->data) {
        std::swap(root->data, root->right->data);
        vunDong(root->right);
    }
}
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
    // Example usage
    Tree T(10);
    T.root->left = new Node(5);
    T.root->right = new Node(15);
    T.root->left->left = new Node(2);
    T.root->left->right = new Node(7);
    vunDong(T.root);
    cout << "Duyệt trung tố: ";
    Trungto(T.root);
    cout << endl;

    cout << "Duyệt tiền tố: ";
    Tiento(T.root);
    cout << endl;

    cout << "Duyệt hậu tố: ";
    Hauto(T.root);
    cout << endl;

    return 0;}

