#include <iostream>
using namespace std;

class DoubleLinkedList {
public:
    class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        // Node(int value) {
        //     this->value = value;
        //     next = nullptr;
        //     prev = nullptr;
        // }
        Node (int value) : value(value), next(nullptr), prev(nullptr) {}
        Node (int value, Node* next) : value(value), next(next), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
    int length;
    DoubleLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            length++;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        length++;
        return;
    }

    void prepend(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
            tail = node;
            length++;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
        length++;
        return;
    }

    void insert(int value, int ind) {
        if (ind < 0 || ind > length) return;
        if (ind == 0) {
            prepend(value);
            return;
        }
        if (ind == length - 1) {
            append(value);
            return;
        }
        Node* node = new Node(value);
        Node* temp = getNode(ind - 1);
        node->next = temp->next;
        node->next->prev = node;
        node->prev = temp;
        temp->next = node;
        length++;
        return;
        
    }

    void RemoveLast() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr; 
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
        length--;
        return;
    }

    void RemoveFirst() {
        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }

        head = head->next;
        head->prev->next = nullptr;
        delete head->prev;
        head->prev = nullptr;
        length--;
        return;
    }

    void RemoveInd(int ind) {
        if (ind < 0 || ind >= length) {
            return;
        }
        if (ind == 0) {
            RemoveFirst();
            return;
        }
        if (ind == length - 1) {
            RemoveLast();
            return;
        }

        Node* temp = getNode(ind);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
        return;
    }

    void Reverse() {
        if (head == NULL || head->next == NULL) {
            return;
        }

        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;
        }
        prev = head;
        head = tail;
        tail = prev;
    }

    

    Node* getNode(int ind) {
        if (ind < 0 || ind >= length) return nullptr;
        Node* temp = head;
        if (ind < length / 2) {
            for (int i = 0; i < ind; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = length - 1; i > ind; i--) {
                temp = temp->prev;
            }
        }
        return temp;
    }

    void setNode(int value, int ind) {
        
        Node* temp = getNode(ind);
        if (temp == nullptr) return ;
        temp->value = value;
        return;
    }

    void display() {
        Node* temp = head;
        cout << "NULL ";
        while (temp != nullptr) {
            cout << "<- " << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoubleLinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.display();
    DoubleLinkedList :: Node* temp = list.getNode(2);
    cout << temp->value << list.length << endl;
    list.RemoveInd(2);
    list.display();
    list.Reverse();
    list.display();
}
