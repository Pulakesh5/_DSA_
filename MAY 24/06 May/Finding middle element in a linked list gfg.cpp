class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        int listLength=0;
        Node *auxHead = head;
        while(auxHead!=nullptr)
        {
            listLength++;
            auxHead = auxHead->next;
        }
        listLength/=2;
        auxHead = head;
        while(listLength--)
            auxHead = auxHead->next;
        return auxHead->data;
    }
};
