// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
// Return the linked list sorted as well.

// Input: head = [1,1,2]
// Output: [1,2]

// Example 2:
// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if (head == NULL) return NULL;
            ListNode* temp = head;
            while (temp != NULL && temp->next != NULL) {
                if (temp->val == temp->next->val) {
                    temp->next = temp->next->next;
                }else {
                    temp = temp->next;
                }
            }
            return head;
        }
    };
int main() {
    int arr[] = {1, 1, 2, 3, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, size);
    
    cout << "Original List: ";
    printList(head);
    
    Solution sol;
    head = sol.deleteDuplicates(head);
    
    cout << "List after removing duplicates: ";
    printList(head);
    
    return 0;
}