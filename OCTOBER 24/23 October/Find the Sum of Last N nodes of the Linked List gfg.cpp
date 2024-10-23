class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    void traverse(struct Node* head, int &n, int &sumOfLastN)
    {
        if(head == nullptr)
            return;
        traverse(head->next, n, sumOfLastN);
        if(n>0)
            sumOfLastN += head->data;
        n--;
    }
    int sumOfLastN_Nodes(struct Node* head, int n) {
        // Code here
        int sumOfLastN = 0;
        traverse(head, n, sumOfLastN);
        return sumOfLastN;
    }
};
