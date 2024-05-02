#include <iostream>
#include<string.h>
using namespace std;

struct SinhVien { 
    char maSV[8]; 
    char hoTen[50]; 
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100]; 
    char lop[12];
    char khoa[7]; 
    };
struct Ngay { 
    int ngay, thang, nam; 
    }; 
struct Node { 
    SinhVien data; 
    Node *link; 
    }; 
struct List { 
    Node *first; 
    Node *last; 
    };
Node *createNode(SinhVien student) {
    Node *newNode = new Node;
    newNode->data = student;
    newNode->link = NULL;
    return newNode;
}
void insertStudent(List *list, SinhVien student) {
    Node *newNode = createNode(student);

    Node *current = list->first;
    Node *prev = NULL;
    while (current && strcmp(current->data.maSV, student.maSV) < 0) {
        prev = current;
        current = current->link;
    }

    if (prev) {
        prev->link = newNode;
    } else {
        list->first = newNode;
    }

    newNode->link = current;

    if (!current) {
        list->last = newNode;
    }
}
void printList(List *list) {
    if (list->first == NULL) {
        cout << "Danh sách sinh viên trống!" << endl;
        return;
    }

    Node *current = list->first;
    while (current) {
        cout << "Mã SV: " << current->data.maSV << endl;
        cout << "Họ tên: " << current->data.hoTen << endl;
        cout << "Giới tính: " << (current->data.gioiTinh ? "Nam" : "Nữ") << endl;
        cout << "Ngày sinh: " << current->data.ngaySinh.ngay << "/" << current->data.ngaySinh.thang << "/" << current->data.ngaySinh.nam << endl;
        cout << "Địa chỉ: " << current->data.diaChi << endl;
        cout << "Lớp: " << current->data.lop << endl;
        cout << "Khoa: " << current->data.khoa << endl;
        cout << "--------------------------------------" << endl;
        current = current->link;
    }
}
void findStudentsSameDOB(List *list) {
    if (list->first == NULL) {
        cout << "Danh sách sinh viên trống!" << endl;
        return;
    }

    Node *current = list->first;
    while (current) {
        string DOB = to_string(current->data.ngaySinh.ngay) + "/" + to_string(current->data.ngaySinh.thang) + "/" + to_string(current->data.ngaySinh.nam);
        Node *sameDOBNodes = NULL;
        Node *temp = current->link;
        while (temp) {
            string tempDOB = to_string(temp->data.ngaySinh.ngay) + "/" + to_string(temp->data.ngaySinh.thang) + "/" + to_string(temp->data.ngaySinh.nam);
            if (tempDOB == DOB) {
                temp->link = sameDOBNodes;
                sameDOBNodes = temp;
                temp = temp->link;
            } else {
                temp = temp->link;
            }
        }

        if (sameDOBNodes) {
            cout << "Sinh viên có cùng ngày sinh " << DOB << ":" << endl;
            Node *printNode = sameDOBNodes;
            while (printNode) {
                cout << "Mã SV: " << printNode->data.maSV << endl;
                cout << "Họ tên: " << printNode->data.hoTen << endl;
                cout << "Giới tính: " << (printNode->data.gioiTinh ? "Nam" : "Nữ") << endl;
                cout << "Ngày sinh: " << printNode->data.ngaySinh.ngay << "/" << printNode->data.ngaySinh.thang << "/" << printNode->data.ngaySinh.nam << endl;
                cout << "Địa chỉ: " << printNode->data.diaChi << endl;
                cout << "Lớp: " << printNode->data.lop << endl;
                cout << "Khoa: " << printNode->data.khoa << endl;
                cout << "--------------------------------------" << endl;
                printNode = printNode->link;
            }
        }

        current = current->link;
    }
}
void removeStudentsSameDOB(List *list) {
    if (list->first == NULL) {
        cout << "Danh sách sinh viên trống!" << endl;
        return;
    }

    Node *current = list->first;
    Node *prev = NULL;
    while (current) {
        string DOB = to_string(current->data.ngaySinh.ngay) + "/" + to_string(current->data.ngaySinh.thang) + "/" + to_string(current->data.ngaySinh.nam);

        Node *sameDOBNodes = NULL;
        Node *temp = current->link;
        while (temp) {
            string tempDOB = to_string(temp->data.ngaySinh.ngay) + "/" + to_string(temp->data.ngaySinh.thang) + "/" + to_string(temp->data.ngaySinh.nam);
            if (tempDOB == DOB) {
                temp->link = sameDOBNodes;
                sameDOBNodes = temp;
                temp = temp->link;
            } else {
                temp = temp->link;
            }
        }

        if (sameDOBNodes) {
            if (prev) {
                prev->link = sameDOBNodes;
            } else {
                list->first = sameDOBNodes;
            }

            current = sameDOBNodes->link;

            Node *toDelete = sameDOBNodes;
            while (toDelete) {
                sameDOBNodes = toDelete->link;
                delete toDelete;
                toDelete = sameDOBNodes;
            }
        } else {
            prev = current;
            current = current->link;
        }
    }
}
int main() {
    List listSV;
    listSV.first = NULL;
    listSV.last = NULL;

    int choice;
    do {
        cout << "\nMENU QUẢN LÝ SINH VIÊN" << endl;
        cout << "1. Nhập sinh viên mới" << endl;
        cout << "2. In danh sách sinh viên" << endl;
        cout << "3. Tìm sinh viên theo ngày sinh" << endl;
        cout << "4. Loại bỏ sinh viên cùng ngày sinh" << endl;
        cout << "0. Thoát chương trình" << endl;
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
            case 1:
                SinhVien newStudent;
                cout << "\nNhập thông tin sinh viên mới:" << endl;
                cout << "Mã SV: ";
                cin >> newStudent.maSV;
                cout << "Họ tên: ";
                cin.ignore(); 
                getline(cin, newStudent.hoTen);
                cout << "Giới tính (Nam = 1, Nữ = 0): ";
                cin >> newStudent.gioiTinh;
                cout << "Ngày sinh (ngay/thang/nam): ";
                cin >> newStudent.ngaySinh.ngay >> newStudent.ngaySinh.thang >> newStudent.ngaySinh.nam;
                cout << "Địa chỉ: ";
                cin.ignore(); 
                getline(cin, newStudent.diaChi);
                cout << "Lớp: ";
                getline(cin, newStudent.lop);
                cout << "Khoa: ";
                getline(cin, newStudent.khoa);

                insertStudent(&listSV, newStudent);
                cout << "\nSinh viên đã được thêm vào danh sách!" << endl;
                break;

            case 2:
                cout << "\nDanh sách sinh viên:" << endl;
                printList(&listSV);
                break;

            case 3:
                cout << "\nNhập ngày sinh (ngay/thang/nam) để tìm kiếm: ";
                int day, month, year;
                cin >> day >> month >> year;

                cout << "\nSinh viên có cùng ngày sinh " << day << "/" << month << "/" << year << ":" << endl;
                findStudentsSameDOB(&listSV, day , month, year);
                break;

            case 4:
                removeStudentsSameDOB(&listSV);
                cout << "\nSinh viên cùng ngày sinh đã được loại bỏ khỏi danh sách!" << endl;
                break;

            case 0:
                cout << "\nThoát chương trình!" << endl;
                break;

            default:
                cout << "\nLựa chọn không hợp lệ! Vui lòng nhập lại." << endl;
        }
    } while (choice != 0);

    Node *current = listSV.first;
    while (current) {
        Node *next = current->link;
        delete current;
        current = next;
    }

    return 0;
}