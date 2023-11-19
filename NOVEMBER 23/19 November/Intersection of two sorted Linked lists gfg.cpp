class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node* intersectionRoot = new Node(-1);
        Node* root = intersectionRoot, *root1 = head1, *root2 = head2;
        int data1, data2;
        // cout<<root1->data<<" "<<root2->data<<endl;
        while(root1 && root2)
        {
            data1 = root1->data;
            data2 = root2->data;
            if(data1==data2)
            {
                root->next = new Node(data1);
                root = root->next;
                // cout<<data1<<endl;
                root1 = root1->next;
                root2 = root2->next;
            }
            else if(data1<data2)
                root1 = root1->next;
            else
                root2 = root2->next;
        }
        return intersectionRoot->next;
    }
};
