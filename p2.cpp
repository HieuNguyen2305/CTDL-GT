#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void Push(int x) {
        Node* p = new Node;
        if (p != nullptr) {
            p->data = x;
            p->next = top;
            top = p;
        }
    }

    int Pop() {
        if (!Empty()) {
            Node* p = top;
            top = p->next;
            int poppedValue = p->data;
            delete p;
            return poppedValue;
        }
        return -1; 
    }

    bool Empty() {
        return top == nullptr;
    }

    void PrintStack() {
        Node* current = top;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    int A[] = {73, 89, 96, 99, 60, 55, 52, 66, 67, 79};
    Stack s;
    for (int i = 0; i < 10; i++) {
        if (A[i] < A[0] && A[i] % 2 == 0) {
            if (!s.Empty()) {
                s.Pop();
            } }
        else {
                s.Push(A[i]);
            }
        }

    s.PrintStack();

    return 0;
}
