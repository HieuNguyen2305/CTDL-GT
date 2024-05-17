#include <iostream>
using namespace std;

struct NodeDT {
    float heso;
    int somu;
    NodeDT* link;
};

struct ListDT {
    NodeDT* fist, * last;
};

void initDT(ListDT* lDT) {
    lDT->fist = NULL;
    lDT->last = NULL;
}

NodeDT* callNode(float hs, int sm) {
    NodeDT* p = new NodeDT;
    if (p == NULL) return NULL;
    p->heso = hs;
    p->somu = sm;
    p->link = NULL;
    return p;
}

void addNode(ListDT* lDT, NodeDT* p) {
    if (lDT->fist == NULL) {
        lDT->fist = lDT->last = p;
    } else {
        lDT->last->link = p;
        lDT->last = p;
    }
}

void attachNode(ListDT* lDT, float hs, int sm) {
    NodeDT* pDT = callNode(hs, sm);
    if (pDT == NULL) return;
    addNode(lDT, pDT);
}

void taoDT(ListDT* lDT) {
    float hs;
    int sm = 0;
    int i = 0;

    cout << "- Bắt đầu nhập đa thức (nhập hệ số 0 để kết thúc):\n";
    do {
        i++;
        cout << "Nhập số phần tử thứ " << i << endl;
        cout << "Số mũ " << sm << endl;
        cout << "Nhập hệ số = ";
        cin >> hs;
        if (hs == 0) break;
        attachNode(lDT, hs, sm);
        sm++;
    } while (hs != 0);

    cout << "Kết thúc nhập\n";
}

void inDT(ListDT lDT) {
    NodeDT* p = lDT.fist;
    cout << "f(x) = ";
    while (p != NULL) {
        cout << p->heso << " * x^" << p->somu;
        if (p->link != NULL && p->heso != 0) cout << " + ";
        p = p->link;
    }
    cout << endl;
}

void congDT(ListDT DT1, ListDT DT2, ListDT& DT3) {
    NodeDT* p1 = DT1.fist;
    NodeDT* p2 = DT2.fist;

    while (p1 != NULL && p2 != NULL) {
        if (p1->somu == p2->somu) {
            float tong = p1->heso + p2->heso;
            attachNode(&DT3, tong, p1->somu);
            p1 = p1->link;
            p2 = p2->link;
        } else if (p1->somu > p2->somu) {
            attachNode(&DT3, p1->heso, p1->somu);
            p1 = p1->link;
        } else {
            attachNode(&DT3, p2->heso, p2->somu);
            p2 = p2->link;
        }
    }

    while (p1 != NULL) {
        attachNode(&DT3, p1->heso, p1->somu);
        p1 = p1->link;
    }
    while (p2 != NULL) {
        attachNode(&DT3, p2->heso, p2->somu);
        p2 = p2->link;
    }
}

int main() {
    ListDT DT1, DT2, DT3;
    initDT(&DT1);
    initDT(&DT2);
    initDT(&DT3);

    cout << "Nhập đa thức 1:\n";
    taoDT(&DT1);
    cout << "\nNhập đa thức 2:\n";
    taoDT(&DT2);
    congDT( DT1, DT2, DT3);}