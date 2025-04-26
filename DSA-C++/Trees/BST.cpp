#include <iostream>
using namespace std;

class BST {
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
    BST() : root(NULL) {}
    bool isEmpty() { return root == NULL; }

    //Height of each node
    int height(Node* node) {
        if (node == NULL) {
            return -1;
        }
        return node->height;
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
        return node;
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
    BST bs;
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    bs.populateSorted(arr, 0, 8);
    bs.Display();
}