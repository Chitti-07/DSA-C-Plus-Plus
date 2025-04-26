// Given head which is a reference node to a singly-linked list. 
// The value of each node in the linked list is either 0 or 1. 
// The linked list holds the binary representation of a number.
// Return the decimal value of the number in the linked list.
// The most significant bit is at the head of the linked list.

// Example 1:
// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10

// Example 2:
// Input: head = [0]
// Output: 0

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            res <<= 1;
            res |= temp->val;
            temp = temp->next;
        }
        return res;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to free linked list memory
void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    vector<int> binaryList = {1, 0, 1}; // Example: Binary 101 -> Decimal 5
    ListNode* head = createLinkedList(binaryList);

    int result = solution.getDecimalValue(head);
    
    cout << "Decimal Value: " << result << endl;

    deleteLinkedList(head);

    return 0;
}
