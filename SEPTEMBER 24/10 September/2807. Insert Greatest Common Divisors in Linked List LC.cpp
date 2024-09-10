class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *originalHead = head, *next;
        while(head->next != nullptr)
        {
            next = head->next;
            int gcd = __gcd(head->val, head->next->val);
            ListNode gcdNode = ListNode(gcd);
            head->next = &gcdNode;
            gcdNode.next = next;
            head = next;
        }
        return originalHead;
    }
};
