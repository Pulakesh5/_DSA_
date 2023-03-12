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
 class comp{
    public:
    bool operator () (ListNode* a, ListNode* b)
    {
        return a->val > b->val;
        
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        
        for(auto it:lists){
            if(it)
                pq.push(it);
        }

        ListNode *head= new ListNode(-1), *tail, *top;
        tail = head;
        
        while(!pq.empty())
        {
            if(pq.top() != NULL)
            {
                top = pq.top();
                pq.pop();
                
                if(top->next != NULL)
                    pq.push(top->next);
                tail->next = top;
                tail = tail->next;
            }
            else
                pq.pop();
        }
        return head->next;
    }
};
