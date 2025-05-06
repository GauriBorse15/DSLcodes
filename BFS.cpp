#include<iostream>
using namespace std;

class Tnode {
 public:
  int data;
  Tnode *left;
  Tnode *right;
  int lbit, rbit;
};

class TBT {
 Tnode *root, *head;
 public:
 TBT() {
  root = NULL;
  head = NULL;
 }
 void createTBT();
 void inorder();
 void preorder();
};

void TBT::createTBT() {
 int flag = 0;
 char ans;
 Tnode *new_node, *temp;

 head = new Tnode();
 head->data = -1;
 head->left = head;
 head->right = head;
 head->lbit = 0;
 head->rbit = 0;

 root = new Tnode();
 cout << "Enter root node: ";
 cin >> root->data;
 head->left = root;
 head->lbit = 1;
 head->right = head;
 head->rbit = 0;

 do {
  new_node = new Tnode();
  cout << "\nEnter new node: ";
  cin >> new_node->data;
  new_node->lbit = 0;
  new_node->rbit = 0;

  temp = root;
  flag = 0;
  while (flag == 0) {
   if (new_node->data < temp->data) {
    if (temp->lbit == 0) {
     new_node->left = temp->left;
     temp->left = new_node;
     temp->lbit = 1;
     new_node->right = temp;
     flag = 1;
    } else {
     temp = temp->left;
    }
   } else if (new_node->data > temp->data) {
    if (temp->rbit == 0) {
     new_node->right = temp->right;
     temp->right = new_node;
     temp->rbit = 1;
     new_node->left = temp;
     flag = 1;
    } else {
     temp = temp->right;
    }
   } else {
    cout << "\nData already exists.";
   }
  }
  cout << "\nDo you want to continue (y/n): ";
  cin >> ans;
 } while (ans == 'y' || ans == 'Y');
}

void TBT::inorder() {
 Tnode *temp;
 temp = root;
 int flag = 0;
 if (root == NULL) {
  cout << "\nTree is empty.";
 } else {
  while (temp != head) {
   if (temp->lbit == 1 && flag == 0) {
    temp = temp->left;
   } else {
    cout << " " << temp->data;
    if (temp->rbit == 1) {
     temp = temp->right;
     flag = 0;
    } else {
     temp = temp->right;
     flag = 1;
    }
   }
  }
 }
}

void TBT::preorder() {
 Tnode *temp;
 temp = root;
 int flag = 0;
 if (root == NULL) {
  cout << "\nTree is empty.";
 } else {
  while (temp != head) {
   if (flag == 0) {
    cout << " " << temp->data;
   }
   if (temp->lbit == 1 && flag == 0) {
    temp = temp->left;
   } else {
    if (temp->rbit == 1) {
     temp = temp->right;
     flag = 0;
    } else {
     temp = temp->right;
     flag = 1;
    }
   }
  }
 }
}

int main() {
 TBT t;
 t.createTBT();
 int ch;

 do {
  cout << "\n1. Inorder Display of threaded binary tree.";
  cout << "\n2. Preorder Display of threaded binary tree.";
  cout << "\n3. Exit.";
  cout << "\nEnter the choice: ";
  cin >> ch;
  switch (ch) {
   case 1:
    t.inorder();
    break;
   case 2:
    t.preorder();
    break;
   default:
    cout << "\nEnter correct choice!!";
    break;
  }
 } while (ch != 3);
 return 0;
}