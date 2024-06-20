#include<iostream>
using namespace std;
struct Node {
  int id; 
  string title; 
  int pageStart; 
  int pageEnd; 
  Node* left; 
  Node* right;
};
Node* createTree() {
  Node nodes[] = {
    {1, "Chương 1: Giới thiệu", 1, 10},
    {2, "Chương 2: Nội dung chính", 11, 45},
    {3, "Mục 2.1", 12, 20},
    {4, "Mục con 2.1.1", 13, 15},
    {5, "Mục con 2.1.2", 16, 18},
    {6, "Mục 2.2", 21, 30},
    {7, "Phụ lục", 31, 45},
    {8, "Phụ lục A", 32, 35},
    {9, "Phụ lục B", 36, 45},
  };

  int numNodes = sizeof(nodes) / sizeof(Node); 

  Node* root = nullptr;
  for (int i = 0; i < numNodes; ++i) {
    root = insertNode(root, nodes[i]);
  }
  return root;
}

Node* insertNode(Node*& root, const Node& newNode) {
  if (root == nullptr) {
    return new Node(newNode);
  }

  if (newNode.id < root->id) {
    root->left = insertNode(root->left, newNode);
  } else {
    root->right = insertNode(root->right, newNode);
  }

  return root;
}
int countChapters(Node* root) {
  if (root == nullptr) return 0;

  if (root->left == nullptr && root->right == nullptr) {
    return 1; 
  }

  return countChapters(root->left) + countChapters(root->right);
}
int findLongestChapter(Node* root, int& maxPageEnd) {
  if (root == nullptr) return 0;

  int leftLength = findLongestChapter(root->left, maxPageEnd);
  int rightLength = findLongestChapter(root->right, maxPageEnd);

  int currentLength = root->pageEnd - root->pageStart + 1;
  if (currentLength > maxPageEnd) {
    maxPageEnd = currentLength;
  }

  return std::max(leftLength, rightLength) + 1; 
}
Node* findAndDeleteNode(Node*& root, int id) {
  if (root == nullptr) return nullptr;

  if (root->id == id) {
    Node* temp = root;
    if (root->left == nullptr) {
      root = root->right;
    } else if (root->right == nullptr) {
      root = root->left;
    } else {
      Node* successor = root->right;
      while (successor->left != nullptr) {
        successor = successor->left;
      }

      successor->left = root->left;
      root = successor;
    }
    delete temp;
    return root;
  } else if (id < root->id) {
    root->left = findAndDeleteNode(root->left, id);
  } else {
    root->right = findAndDeleteNode(root->right, id);
  }

  updatePageNumbers(root);
  return root;
}

void updatePageNumbers(Node* root) {
  if (root == nullptr) return;

  int prevEnd = root->pageStart - 1;
  updatePageNumbers(root->left);
  if (root->left != nullptr) {
    root->pageStart = root->left->pageEnd + 1;
  }

  updatePageNumbers(root->right);
  if (root->right != nullptr) {
    root->pageEnd = root->right->pageEnd + 1;
  }

  if (root->left != nullptr) {
    updateSubtreePageNumbers(root->left, root->pageStart);
  }
  if (root->right != nullptr) {
    updateSubtreePageNumbers(root->right, root->pageStart);
  }
}

void updateSubtreePageNumbers(Node* root, int parentStart) {
  if (root == nullptr) return;

  root->pageStart = parentStart + 1;
  updateSubtreePageNumbers(root->left, root->pageStart);
  updateSubtreePageNumbers(root->right, root->pageStart);
}
void printChapterTitle(Node* root, int chapterId) {
  if (root == nullptr) return;

  if (root->id == chapterId) {
    std::cout << root->title << std::endl;
    return;
  } else if (chapterId < root->id) {
    printChapterTitle(root->left, chapterId);
  } else {
    printChapterTitle(root->right, chapterId);
  }
}
void deleteTree(Node* root) {
  if (root == nullptr) return;

  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}
int main() {
  Node* root = createTree();


  int numChapters = countChapters(root);
  cout << "Số chương: " << numChapters << endl;

  int maxPageEnd = 0;
  int longestChapterId = findLongestChapter(root, maxPageEnd);
  cout << "Chương dài nhất (" << maxPageEnd << " trang): " << longestChapterId << endl;

  int idToDelete = 2; 
  root = findAndDeleteNode(root, idToDelete);
  cout << "Mục " << idToDelete << " đã được xóa." << endl;

  printChapterTitle(root, 4); 

  deleteTree(root);

  return 0;
}
