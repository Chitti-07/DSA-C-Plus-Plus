#include <iostream>
using namespace std;

class SegmentTree {
public:
    class Node {
    public:
        int data;
        int start;
        int end;
        Node* left;
        Node* right;

        Node(int data) : data(data), left(NULL), right(NULL) {}
        Node(int start, int end) : start(start), end(end) {}
    };

    Node* root;
    SegmentTree() {}

    Node* ConstructTree(int arr[], int start, int end) {
        if (start == end) {
            Node* leaf = new Node(start, end);
            leaf->data = arr[start];
            return leaf;
        }

        Node* node = new Node(start, end);
        int mid = (start + end)/2;
        node->left = this->ConstructTree(arr, 0, mid);
        node->right = this->ConstructTree(arr, mid + 1, end);
        node->data = node->left->data + node->right->data;
        return node;
        
    }
    SegmentTree(int arr[], int size) {
        this->root = ConstructTree(arr, 0, size-1);
    }

    void Display(Node* node) {
        string str = "";
        if (node->left == NULL) {
            str = str + "Interval = [" + to_string(node->left->start) + "-" + to_string(node->left->end) + "] and data: " + to_string(node->left->data) + " => ";
        }else {
            str = str + "No left child";
        }
        str = str + "Interval = [" + to_string(node->start) + "-" + to_string(node->end) + "] and data: " + to_string(node->data) + " => ";

        if (node->right == NULL) {
            str = str + "Interval = [" + to_string(node->right->start) + "-" + to_string(node->right->end) + "] and data: " + to_string(node->right->data) + " => ";
        }else {
            str = str + "No right child";
        }
        cout << str << endl;

        if (node->left != NULL) {
            Display(node->left);
        }

        if (node->right != NULL) {
            Display(node->right);
        }
        
    }
    int update(Node* node, int ind, int value) {
        if (ind >= node->start && ind <= node->end) {
            if (ind == node->start && ind == node->end) {
                node->data = value;
                return node->data;
            }else {
                int leftans = update(node->left, ind, value);
                int rightans = update(node->right, ind, value);
                node->data = leftans + rightans;
                return node->data;
            }
        }
        return node->data;
    }
    int update(int ind, int value) {
        this->root->data = update(root, ind, value);
    }
    void Display() {
        Display(root);
    }
    int query(Node* node, int qs, int qe) {
        if (node->start >= qs && node->end <= qe) {
            return node->data;
        }else if (node->start > qe || node->end < qs) {
            return 0;
        }else {
            return this->query(node->left, qs, qe) + this->query(node->right, qs, qe);
        }
    }
    int query(int qs, int qe) {
        query(this->root, qs, qe);
    }
};

int main() {
    int arr[8] = {3, 8, 6, 7, -2, -8, 4, 9};
    SegmentTree st(arr, 8);
    st.Display();    
}