#include <iostream>
using namespace std;

class AVL {
public:
    class Node {
    public:
        int value;
        Node* left;
        Node* right;
        int height;

        Node(int value) : value(value), left(NULL), right(NULL) {}
        int getValue() { return value; }
    };

    Node* root;

    //Constructor
    AVL() : root(NULL) {}
    bool isEmpty() { return root == NULL; }

    //Height of each node
    int height(Node* node) {
        if (node == NULL) {
            return -1;
        }
        return node->height;
    }

    Node* RotateRight(Node* p) {
        Node* c = p->left;
        Node* t = c->right;

        c->right = p;
        p->left = t;

        p->height = max(height(p->left), height(p->right)) + 1;
        c->height = max(height(c->left), height(c->right)) + 1;

        return c;
    }

    Node* RotateLeft(Node* c) {
        Node* p = c->right;
        Node* t = p->left;

        p->left = c;
        c->right = t;

        p->height = max(height(p->left), height(p->right)) + 1;
        c->height = max(height(c->left), height(c->right)) + 1;

        return p;
    }

    Node* rotate(Node* node) {
        // Left Heavy
        if (height(node->left) - height(node->right) > 1) {
            //Left-Left
            if (height(node->left->left) - height(node->left->right) > 0) {
                return RotateRight(node);
            }
            //Left-Right
            if (height(node->left->left) - height(node->left->right) < 0) {
                node->left = RotateLeft(node->left);
                return RotateRight(node);
            }
        }

        //Right Heavy
        if (height(node->left) - height(node->right) < -1) {
            //Right-Right
            if (height(node->right->left) - height(node->right->right) < 0) {
                return RotateLeft(node);
            }
            //Right-Left
            if(height(node->right->left) - height(node->right->right) > 0) {
                node->right = RotateRight(node->right);
                return RotateLeft(node);
            }
        }
        return node;
    }

    Node* insert(Node* node, int value) {

        if (node == NULL) {
            node = new Node(value);
            return node;
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        }
        if (value > node->value) {
            node->right = insert(node->right, value);
        }
        node->height = max(height(node->left), height(node->right)) + 1;
        return rotate(node);
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void populate(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            insert(arr[i]);
        }
    }

    void populateSorted(int arr[], int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start)/2;
        insert(arr[mid]);

        populateSorted(arr, start, mid);
        populateSorted(arr, mid + 1, end);
    }

    void populateSorted(int arr[], int size) {
        populateSorted(arr, 0, size-1);
    }

    bool isBalanced(Node* node) {
        if (node == NULL) {
            return true;
        }
        return (abs(height(node->left) - height(node->right)) <= 1) && isBalanced(node->left) && isBalanced(node->right);
    }
    bool isBalanced() {
        return isBalanced(root);
    }
    void PreOrder(Node* node) {
        if (node == NULL) {
            return;
        }
        cout << node->value << " ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
    void PreOrder() {
        PreOrder(root);
    }

    void InOrder(Node* node) {
        if (node == NULL) {
            return;
        }
        InOrder(node->left);
        cout << node->value << " ";
        InOrder(node->right);
    }
    void InOrder() {
        InOrder(root);
    }

    void PostOrder(Node* node) {
        if (node == NULL) {
            return;
        }
        PostOrder(node->left);
        PostOrder(node->right);
        cout << node->value << " ";
    }
    void PostOrder() {
        PostOrder(root);
    }

    void Display(Node* node, string detatil) {
        if (node == NULL) {
            return;
        }
        cout << detatil << node->value << endl;
        Display(node->left, "left child of " + to_string(node->value) + ": ");
        Display(node->right, "Right child of " + to_string(node->value) + ": ");
    }

    void Display() {
        Display(root, "Root Node: ");
    }
};  

int main() {
    AVL av;
    for (int i = 0; i < 1000; i++) {
        av.insert(i);
    }
    //av.Display();
    cout << av.height(av.root);
}