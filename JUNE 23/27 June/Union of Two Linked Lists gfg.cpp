struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        Node *root1 = head1, *root2 = head2;
        Node *head = NULL, *root = NULL;
        root = head;
        vector<int> datas;
        while(root1)
        {
            datas.push_back(root1->data);
            root1 = root1->next;
        }
        
        while(root2)
        {
            datas.push_back(root2->data);
            root2 = root2->next;
        }
        
        set<int> st(datas.begin(), datas.end());
        vector<int> data(st.begin(), st.end());
        for(int i=0; i<data.size(); i++)
        {
            if(!head)
                head = new Node(data[i]);
            else
            {
                head -> next = new Node(data[i]);
                head = head -> next;
            }
            cout<<head->data<<" ";
        }
        return root;
    }
