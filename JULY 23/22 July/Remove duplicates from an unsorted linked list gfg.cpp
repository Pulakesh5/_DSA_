class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
    //   your code goes here
        set<int> uniques;
        Node* root = head->next, *prev = head;
        uniques.insert(head->data);
        while(root)
        {
            
            if(uniques.find(root->data)!=uniques.end())
            {
                // cout<<"occured already "<<root->data<<endl;
                root = root->next;
                continue;
            }
            // else
                // cout<<"occuring first time "<<root->data<<endl;
            uniques.insert(root->data);
            prev->next = root;
            prev = root; 
            root = root->next;
        }
        prev->next = NULL;
        return head;
    }
};
