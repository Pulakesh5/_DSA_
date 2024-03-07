/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int listLen = 0;
        ListNode* listHead = head;
        while(listHead!=nullptr)
        {
            listLen++;
            listHead = listHead->next;
        }

        int middle = listLen/2+1;
        listHead = head;
        while(--middle)
            listHead = listHead->next;

        return listHead;
    }
};
