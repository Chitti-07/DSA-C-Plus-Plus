#include <iostream>
using namespace std;

class BTree {
public:
    class Node {
    public:
        int value;
        Node* left;
        Node* right;
    public:
        Node(int value) : value(value), left(NULL), right(NULL) {}
    };

    Node* root;
    BTree() : root(NULL){}

    void populate(istream& input, Node* node) {
        bool left;
        cout << "Do you want to enter value to left of " << node->value << ": ";
        input >> left;
        if (left) {
            cout << "Enter the value to left of " << node->value << ": ";
            int value;
            input >> value;
            node->left = new Node(value);
            populate(input, node->left);
        }
        cout << "Do you want to enter value to right of " << node->value << ": ";
        bool right;
        input >> right;
        if (right) {
            cout << "Enter the value to left of " << node->value << ": ";
            int value;
            input >> value;
            node->right = new Node(value);
            populate(input, node->right);
        }
    }

    void populate(istream& input) {
        int value;
        cout << "Enter the root value: ";
        input >> value;
        root = new Node(value);
        return populate(input, root);
    }

    void Display(Node* node, int level) {
        if (node == NULL) {
            return;
        }
        Display(node->right, level + 1);
        if (level != 0) {
            for (int i = 0; i < level; i++) {
                cout << "|\t\t ";
            }
            cout << "|---------> " << node->value << endl;
        }else {
            cout << node->value << endl;
        }
        Display(node->left, level + 1);
    }
    void Display() {
        Display(root, 0);
    }
};

int main() {
    BTree BT;
    BT.populate(cin);
    BT.Display();
}