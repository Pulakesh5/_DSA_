class Solution {
  public:
    int count(struct Node* head, int key) {
        // add your code here
        int occurenceCount = 0;
        while(head != nullptr)
        {
            occurenceCount += (head->data == key);
            head = head->next;
        }
        return occurenceCount;
    }
};
