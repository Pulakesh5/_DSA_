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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || head==nullptr)
            return head;

        int len = 0;
        ListNode* dummy = head;
        while(dummy)
        {
            len++;
            dummy = dummy->next;
        }
        
        int last = (len/k)*k;

        ListNode *prev = NULL, *currNode = head, *nxt;
        ListNode *lastGroupEnd = NULL, *ans = NULL, *currGroupStart = head;
        for(int i=0; i<last; i++)
        {
            nxt = currNode->next;
            currNode->next = prev;
            prev = currNode;
            currNode = nxt;

            if((i%k) == k-1)
            {
                if(lastGroupEnd)
                    lastGroupEnd->next = prev;
                if(!ans)
                    ans = prev;
                lastGroupEnd = currGroupStart;
                currGroupStart = currNode;
            }
        }
        // cout<<lastGroupEnd->val<<" "<<currGroupStart->val<<endl;
        lastGroupEnd->next = currGroupStart;
        return ans;
    }
};
