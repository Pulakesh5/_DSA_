class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        vector<int> v;
        struct Node* head=head_ref;
        while(head)
        {
            v.push_back(head->data);
            head = head->next;
        }
        sort(v.begin(), v.end());
        int N=v.size();
        head = head_ref;
        for(int i=0; i<N; i++)
        {
            head->data = v[i];
            // cout<<head->data<<endl;
            head = head->next;
        }
        return head_ref;
    }
    
};
