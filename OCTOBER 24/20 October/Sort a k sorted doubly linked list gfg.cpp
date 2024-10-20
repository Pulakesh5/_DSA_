class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        DLLNode *curr = head, *prev = head;
        if(head==nullptr || head->next==nullptr)
            return head;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        while(prev) {
            if(minHeap.size()==k+1 || curr==NULL)
            {
                prev->data = minHeap.top();
                minHeap.pop();
                prev = prev->next;
            }
            else
            {
                minHeap.push(curr->data);
                curr = curr->next;
            }
        }
        return head;
    }
};
