// LeetCode #19 - Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Topic: Linked List | Two Pointers
// Level: Medium

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == nullptr) {
            return head->next;
        }
        fast = fast->next;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

ListNode *createLinkedList(vector<int> nodes) {
    int l = nodes.size();
    if (l == 1) {
        return new ListNode(nodes[0]);
    }
    else {
        vector<int> rest = std::vector(nodes.begin() + 1, nodes.end());
        return new ListNode(nodes[0], createLinkedList(rest));
    }
};

void printInOrder(ListNode *node) {
    if (node == nullptr)
        return;
    cout << node->val << " ";
    printInOrder(node->next);
}

int main() {
    Solution sol;
    vector<int> list_1 = {1, 2, 3, 4, 5};
    ListNode *nodes_1 = createLinkedList(list_1);
    ListNode *list_node_1 = sol.removeNthFromEnd(nodes_1, 5);
    printInOrder(list_node_1);
    return 0;
}