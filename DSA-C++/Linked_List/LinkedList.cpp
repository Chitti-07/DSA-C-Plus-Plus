#include <iostream>
using namespace std;

class LinkedList {
public:
    class Node {
    public:
        int value;
        Node* next;

        Node(int value) : value(value), next(nullptr){}

        Node(int value, Node* next) : value(value), next(next){}
    };
public:
    Node* head;
    Node* tail;
    int length;

    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    // Insert at first
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
        length++;
    }

    void InsertInsex(int value, int index) {
        if (index < 0 || index > length - 1) {
            return;
        }
        if (index == 0) {
            insert(value);
            return;
        }
        if (index == length - 1) {
            append(value);
            return;
        }
        // Node* temp = head;
        // for (int i = 0; i < index; i++) {
        //     temp = temp->next;
        // }
        Node* ind = getNode(index - 1);
        Node* newNode = new Node(value);
        newNode->next = ind->next;
        ind->next = newNode;
        length++;
    }

    void append(int value) {
        Node* node = new Node(value);
        if (head == nullptr || tail == nullptr) {
            head = node;
            tail = node;
            return;
        }
        tail->next = node;
        tail = node;
        length++;
    }

    void RemoveFirst() {
        if (head == nullptr) {
            return;
        }else if (head == tail) {
            head = nullptr;
            return;
        }else {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        length--;
    }

    void RemoveLast() {
        Node* temp = head;
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        length--;
    }

    void RemoveInd(int ind) {
        if (ind < 0 || ind >= length) return;
        if (ind == 0) {
            RemoveFirst();
            return;
        }
        if (ind == length - 1) {
            RemoveLast();
            return;
        }
        Node* prev = getNode(ind - 1);
        if (prev == nullptr || prev->next == nullptr) return;
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }

    void Reverse(Node* node) {
        Node* prev = NULL;
        Node* curr = node;
        Node* nextptr = node->next;

        //tail = head;
        while (curr) {
            curr->next = prev;
            prev = curr;
            curr = nextptr;
            if (nextptr) {
                nextptr = nextptr->next;
            }
        }
        head = prev;
    }

    void ReverseRange(int start, int end) {
        if (start < 0 || end >= length || (end < start) || (start == end)) return;

        Node* prev = NULL;
        Node* curr = head;
        Node* nextptr = curr->next;

        for (int i = 0; i < start; i++) {
            prev = curr;
            curr = nextptr;
            if (nextptr != NULL) {
                nextptr = nextptr->next;
            }
        }

        Node* lastNode = prev;
        Node* newEnd = curr;

        for (int i = 0; curr && i < (end - start) + 1; i++) {
            curr->next = prev;
            prev = curr;
            curr = nextptr;
            if (nextptr) {
                nextptr = nextptr->next;
            }
        }

        if (lastNode) {
            lastNode->next = prev;
        }else {
            head = prev;
        }

        newEnd->next = curr;
    }

    // void swapK(int k) {
    //     if (k < 0 || head == nullptr || head->next == nullptr) {
    //         return;
    //     }
    //     Node* first = head;
    //     Node* sec = first->next;
    //     Node* prev = nullptr;

    //     while (first != nullptr && sec != nullptr) {
    //         Node* thrd = sec->next;
    //         sec->next = first;
    //         first->next = thrd;
    //         if (prev != nullptr) {
    //             prev->next = sec;
    //         }else {
    //             head = sec;
    //         }

    //         prev = first;
    //         first = thrd;
    //         if (thrd != nullptr) {
    //             sec = thrd->next;
    //         }else {
    //             sec = nullptr;
    //         }
    //     }
    // }

    // void swapKNodes(int k) {
    //     if (head == nullptr || k <= 1 || k > length) {
    //         return; // No need to swap if the list is empty, k is invalid, or k is larger than the list length
    //     }
    
    //     Node* prev = nullptr;
    //     Node* curr = head;
    //     Node* nextptr = nullptr;
    
    //     Node* lastNodeOfPrevSegment = nullptr;
    //     Node* lastNodeOfCurrentSegment = head;
    
    //     while (curr != nullptr) {
    //         // Start of the current segment
    //         //Node* startOfCurrentSegment = curr;
    
    //         // Reverse k nodes
    //         for (int i = 0; i < k && curr != nullptr; i++) {
    //             nextptr = curr->next;
    //             curr->next = prev;
    //             prev = curr;
    //             curr = nextptr;
    //         }
    
    //         // Connect the previous segment to the current reversed segment
    //         if (lastNodeOfPrevSegment != nullptr) {
    //             lastNodeOfPrevSegment->next = prev;
    //         } else {
    //             // If there is no previous segment, update the head
    //             head = prev;
    //         }
    
    //         // Connect the end of the current reversed segment to the next segment
    //         lastNodeOfCurrentSegment->next = curr;
    
    //         // Update pointers for the next iteration
    //         lastNodeOfPrevSegment = lastNodeOfCurrentSegment;
    //         lastNodeOfCurrentSegment = curr;
    //     }
    // }

    void SwapKNodes(int k) {
        if (k < 0 || head == NULL || head->next == NULL) {
            return;
        }

        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        Node* LastNode = NULL;
        Node* NewEnd = curr; // Initially current is pointing to Head

        while (curr != NULL) {
            for (int i = 0; i < k && curr != NULL; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            if (LastNode != NULL) {
                LastNode->next = prev;
            }else {
                head = prev;
            }

            NewEnd->next = curr;

            LastNode = NewEnd;
            NewEnd = curr;
        }
    }

    void sort(Node*& head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        bool isSwapped;
        Node* lastSorted = nullptr;

        do {
            isSwapped = false;
            Node* prev = nullptr;
            Node* curr = head;
            Node* nextptr = curr->next;

            while (nextptr != lastSorted) {
                if (curr->value > nextptr->value) {
                    isSwapped = true;
                    curr->next = nextptr->next;
                    nextptr->next = curr;
                    if (prev == nullptr) {
                        head = nextptr;
                    } else {
                        prev->next = nextptr;
                    }
                    prev = nextptr;
                    nextptr = curr->next;
                } else {
                    prev = curr;
                    curr = nextptr;
                    nextptr = nextptr->next;
                }
            }
            lastSorted = curr;
        } while (isSwapped);
    }

    void RemoveDuplicate() {
        Node* t1 = head;

        while (t1 != nullptr && t1->next != nullptr) {
            Node* prev = t1;
            Node* t2 = t1->next;

            while(t2 != nullptr) {
                if (t1->value == t2->value) {
                    prev->next = t2->next;
                    delete t2;
                    t2 = prev->next;
                }else {
                    prev = t2;
                    t2 = t2->next;
                }
            }
            t1 = t1->next;
        }
    }

    Node* getNode(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void setNode(int value, Node* node) {
        if (node == nullptr) {
            return;
        }
        if (node == head) {
            head->value = value;
            return;
        }

        Node* temp = head;
        while (temp != node) {
            temp = temp->next;
        }
        temp->value = value;
        return;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~LinkedList() {
        Node* temp = head;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
        //cout << "destroyed";
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);

    list.display();
    list.Reverse(list.head);
    list.display();
    //list.ReverseRange(1, 3);
    //list.display();
    list.sort(list.head);
    list.display();
    list.RemoveDuplicate();
    list.display();
    list.SwapKNodes(2);
    list.display();
    list.ReverseRange(0, 3);
    list.display();
}