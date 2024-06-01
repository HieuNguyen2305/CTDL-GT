#include<iostream>
using namespace std;
struct Node{
    int sbd;
    string hoTen;
    Node* left;
    Node* right;
    Node(int s, string h, Node*l, Node* r){
        sbd = s;
        hoTen = h;
        left = l;
        right = r;
    }
};
class BSTree{
    public:
    BSTree(){
        root = NULL;
    }
    ~BSTree(){
        makeEmpty();
    }
    bool isEmpty(){
        return (root == NULL);
    }
    void makeEmpty(){
        makeEmpty(root);
    }
    void insert(int sbd, string hoTen){
        return insert(sbd,hoTen,root);
    }
    Node* search(int sbd){
        return search(sbd, root);
    }
    private: 
    Node* root;
    void makeEmpty(Node *& t){
        if (t == NULL){
            return;
        }
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }
    void insert(int sbd, string hoTen, Node*& t){
        if (t == NULL){
            t = new Node(sbd, hoTen, NULL, NULL);
        }
        else if(sbd<t->sbd){
            insert(sbd,hoTen,t->left);
        }
        else if(sbd>t->sbd){
            insert(sbd,hoTen,t->right);}
        else;
    }
    Node* search(int sbd, Node* t)

    {

        if (t == NULL)

            return NULL;

        if (sbd < t->sbd)

            return search(sbd, t->left);

        else if (sbd > t->sbd)

            return search(sbd, t->right);

        else

            return t;

        }
    void tienTo(Node* t) {
        if (t != NULL) {
            cout << t->sbd << " " << t->hoTen << endl;
            tienTo(t->left);
            tienTo(t->right);
        }
    }

    void trungTo(Node* t) {
        if (t != NULL) {
            trungTo(t->left);
            cout << t->sbd << " " << t->hoTen << endl;
            trungTo(t->right);
        }
    }

    void hauTo(Node* t) {
        if (t != NULL) {
            hauTo(t->left);
            hauTo(t->right);
            cout << t->sbd << " " << t->hoTen << endl;
        }
    }
    void vunDong(Node* root) {
    if (root == NULL) return;

    // Vun đống con trái
    vunDong(root->left);

    // Vun đống con phải
    vunDong(root->right);

    // Kiểm tra và đổi vị trí nếu cần thiết
    if (root->left != NULL && root->left->sbd > root->sbd) {
        std::swap(root->sbd, root->left->sbd);
        vunDong(root->left);
    }
    if (root->right != NULL && root->right->sbd > root->sbd) {
        std::swap(root->sbd, root->right->sbd);
        vunDong(root->right);
    }
}
void Trungto(Node* p) {
    if (p != nullptr) {
        Trungto(p->left);
        cout << p->sbd << " ";
        Trungto(p->right);
    }
}

};
int main() {

BSTree bst;
bst.insert(5, "Tuan"); 

bst.insert(6, "Lan"); 
bst.insert(3, "Cong"); 
bst.insert(8, "Huong"); 
bst.insert(7, "Binh"); 
bst.insert(4, "Hai"); 
bst.insert(2, "Son"); 
 Node * n1 = bst.search(4); 
 Node * n2 = bst.search(9); 
  if (n1 != NULL) cout << "Sinh vien voi SBD=4 la " << n1->hoTen << endl; 
  if (n2 == NULL) cout << "Khong tim thay sinh vien voi SBD=9" << endl;
 bst.makeEmpty(); 
 if (bst.isEmpty()) cout << "Cay da bi xoa rong" << endl; 
 return 0;

}