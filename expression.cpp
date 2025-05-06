#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = NULL;
    }
};

// Check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Construct Expression Tree from Prefix expression
Node* constructTree(string prefix) {
    stack<Node*> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        Node* node = new Node(c);

        if (isOperator(c)) {
            node->left = st.top(); st.pop();
            node->right = st.top(); st.pop();
        }

        st.push(node);
    }

    return st.top();
}

// Non-recursive postorder traversal using two stacks
void postorder(Node* root) {
    if (!root) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* temp = s1.top(); s1.pop();
        s2.push(temp);

        if (temp->left) s1.push(temp->left);
        if (temp->right) s1.push(temp->right);
    }

    cout << "\nPostorder Traversal: ";
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

// Recursively delete tree
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Main function
int main() {
    string expr;
    cout << "Enter prefix expression (e.g. +--a*bc/def): ";
    cin >> expr;

    Node* root = constructTree(expr);
    cout << "Expression Tree constructed successfully." << endl;

    postorder(root);

    deleteTree(root);
    cout << "Expression Tree deleted successfully." << endl;

    return 0;
}
