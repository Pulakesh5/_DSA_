 class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node* root = head;
        vector<int> data;
        while(root)
        {
            data.push_back(root->data); 
            root = root->next;
        }
        root = head;
        while(root)
        {
            root->data = data.back();
            data.pop_back();
            root = root->next;
        }
        return head;
    }
};
