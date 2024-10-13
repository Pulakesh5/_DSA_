class Solution {
  public:
    void deleteAlt(struct Node *head) {
        // Code here
        Node *currNode = head;
        Node *next, *nextToNext;
        while(currNode!=nullptr && currNode->next != nullptr) {
            next = currNode->next;
            nextToNext = currNode->next->next;
            currNode->next = nextToNext;
            currNode = nextToNext;
        }
        // return head;
    }
};
