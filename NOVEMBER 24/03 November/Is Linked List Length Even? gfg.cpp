class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Code here
        int isEven = 1;
        Node *ptr = *head;
        while(ptr)
        {
            ptr = ptr->next;
            isEven = 1-isEven;
        }
        return isEven;
    }
};
