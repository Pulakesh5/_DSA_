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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)
            return {-1, -1};
        int firstCriticalPoint = -1, lastCriticalPoint = 1e6;
        int prevVal = head->val;
        head = head->next;
        int currVal, nextVal, pos=1;
        vector<int> ans = {1000000, -1000000};
        while(head->next!=nullptr)
        {
            currVal = head->val;
            nextVal = head->next->val;
            if((prevVal > currVal && currVal < nextVal) || (prevVal < currVal && currVal > nextVal))
            {
                if(firstCriticalPoint==-1)
                    firstCriticalPoint = pos;
                if(pos - lastCriticalPoint > 0)
                    ans[0] = min(ans[0], pos-lastCriticalPoint);
                if(pos-firstCriticalPoint>0)
                    ans[1] = pos-firstCriticalPoint;
                lastCriticalPoint = pos;
                // cout<<firstCriticalPoint<<" "<<lastCriticalPoint<<endl;
                // cout<<ans[0]<<" "<<ans[1]<<endl;
            }
            pos++;
            prevVal = currVal;
            head = head->next;
        }
        if(ans[0]>100000)
            ans[0] = -1;
        if(ans[1]<0)
            ans[1] = -1;

        return ans;
    }
};
