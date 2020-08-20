#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        auto last = head;
        ListNode *pre_last;
        while (last->next) {
            pre_last = last;
            last = last->next;
        }
        pre_last->next = nullptr;
        auto next = head->next;
        reorderList(next);
        head->next = last;
        last->next = next;
    }
};

int main() {
    // Given 1->2->3->4, reorder it to 1->4->2->3.
    // Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
    auto list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);


    Solution solution;
    solution.reorderList(list);

    auto node = list;
    while (node) {
        std::cout << node->val << " ";
        node = node->next;
    }

    return 0;
}

