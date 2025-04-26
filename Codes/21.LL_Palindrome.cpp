// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

// Example 1:
// Input: head = [1,2,2,1]
// Output: true

// Example 2:
// Input: head = [1,2]
// Output: false

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* midNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* Reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // Function implementation goes here
        
        ListNode* mid = midNode(head);
        ListNode* secondHead = Reverse(mid);

        while (head != NULL && secondHead != NULL) {
            if (head->val != secondHead->val) {
                return false;
            }
            head = head->next;
            secondHead = secondHead->next;
        }
        return true;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Solution solution;
    
    int arr[] = {1, 2, 1};  // Example palindrome list
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createLinkedList(arr, size);
    printLinkedList(head);

    bool result = solution.isPalindrome(head);
    cout << "Is Palindrome: " << (result ? "true" : "false") << endl;

    return 0;
}
