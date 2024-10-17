class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        if(head == nullptr)
            return {nullptr, nullptr};
        Node *list1=head, *list2=head->next;
        vector<Node*> heads = {list1, list2};
        while(list1 && list2 ) {
            if(list1->next)
                list1->next = list1->next->next;
            else
                list1->next = nullptr;
            list1 = list1->next;
            
            if(list2->next)
                list2->next = list2->next->next;
            else
                list2->next = nullptr;
            list2 = list2->next;
        }
        

        return heads;
    }
};
