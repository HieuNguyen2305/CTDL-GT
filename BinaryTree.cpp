#include <iostream>

template<typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};


template<typename T>
class BinaryTree {
public:
    using PNode = Node<T>*;

    BinaryTree() : root(nullptr), size(0) {}


    void InitBTree() {
        deleteTree(root);
        root = nullptr;
        size = 0;
    }


    void InsertParent(T x, PNode P) {
        PNode newNode = new Node<T>(x);
        if (P == root) {
            newNode->left = root;
            root = newNode;
        } else {
            newNode->left = P;
            replaceNodeInParent(P, newNode);
        }
        ++size;
    }
    void InsertLeftChild(T x, PNode P) {
        if (P) {
            P->left = new Node<T>(x);
            ++size;
        }
    }


    void InsertRightChild(T x, PNode P) {
        if (P) {
            P->right = new Node<T>(x);
            ++size;
        }
    }

    PNode FindNode(T x) {
        return findNodeRecursive(root, x);
    }

    void DeleteCurrentNode(PNode P) {
        if (P) {
            if (P == root) {
                deleteTree(root);
                root = nullptr;
                size = 0;
            } else {
                deleteNode(P);
                --size;
            }
        }
    }

    void DeleteLeftChild(PNode P) {
        if (P && P->left) {
            deleteTree(P->left);
            P->left = nullptr;
            --size;
        }
    }

    void DeleteRightChild(PNode P) {
        if (P && P->right) {
            deleteTree(P->right);
            P->right = nullptr;
            --size;
        }
    }

    int GetSize() const {
        return size;
    }

private:
    PNode root;
    int size;

    void replaceNodeInParent(PNode oldNode, PNode newNode) {
        PNode parent = findParent(root, oldNode);
        if (parent) {
            if (parent->left == oldNode) {
                parent->left = newNode;
            } else if (parent->right == oldNode) {
                parent->right = newNode;
            }
        }
    }

    PNode findParent(PNode root, PNode child) {
        if (!root) return nullptr;
        if (root->left == child || root->right == child) return root;
        PNode found = findParent(root->left, child);
        if (found) return found;
        return findParent(root->right, child);
    }

    PNode findNodeRecursive(PNode node, T x) {
        if (!node) return nullptr;
        if (node->data == x) return node;
        PNode found = findNodeRecursive(node->left, x);
        if (found) return found;
        return findNodeRecursive(node->right, x);
    }

    void deleteTree(PNode node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    void deleteNode(PNode node) {
        if (node) {
            if (node->left) deleteTree(node->left);
            if (node->right) deleteTree(node->right);
            delete node;
        }
    }
};

int main() {
    BinaryTree<int> bt;
    bt.InitBTree();

    auto root = new Node<int>(1);
    bt.InsertParent(1, root);

    bt.InsertLeftChild(2, root);
    bt.InsertRightChild(3, root);

    auto node2 = bt.FindNode(2);
    auto node3 = bt.FindNode(3);

    std::cout << "Node 2: " << (node2 ? node2->data : -1) << std::endl;
    std::cout << "Node 3: " << (node3 ? node3->data : -1) << std::endl;

    std::cout << "Size: " << bt.GetSize() << std::endl;

    bt.DeleteLeftChild(root);
    std::cout << "Size after deleting left child: " << bt.GetSize() << std::endl;

    bt.DeleteCurrentNode(root);
    std::cout << "Size after deleting root: " << bt.GetSize() << std::endl;

    return 0;
}

