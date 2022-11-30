class Solution{ 
public:
    void reorderList(Node* head) {
        // Your code here
        Node* root=head;
        vector<int> v;
        while(root)
        {
            v.push_back(root->data);
            root=root->next;
        }
        
        reverse(v.begin()+(v.size()+1)/2,v.end());
    
        int l=0,r=v.size()-1;
        root=head;
        while(l<r && root && root->next)
        {
            root->data=v[l++];
            root=root->next;
            root->data=v[r--];
            root=root->next;
        }
        
        head=root;
        
    }
};
