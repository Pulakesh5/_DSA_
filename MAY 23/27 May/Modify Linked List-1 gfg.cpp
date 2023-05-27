class Solution{
    public:
    struct Node* ptr;
    int index = 0, count = 1;
    void fun(struct Node* node)
    {
        if(node->next)
        {
            count++;
            fun(node->next);
        }
        if(index==(count/2)) return;
        int ptrData = ptr->data;
        ptr->data = node->data - ptrData;
        node->data = ptrData;
        ptr = ptr->next;
        index++;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        ptr = head;
        fun(head);
        return head;
    }
};
