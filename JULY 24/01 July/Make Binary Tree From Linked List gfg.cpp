class Solution {
  public:
    void convert(Node *head, TreeNode *&root) {
        if(!head)
            return;
        root = new TreeNode(head->data);
        
        map<int, TreeNode*> listToTree;
        listToTree[1] = root;
        head = head->next;
        int pos=2, parent;
        TreeNode* node;
        while(head!=nullptr)
        {
            parent = pos/2;
            node = new TreeNode(head->data);
            listToTree[pos] = node;
            
            if(pos&1)
                listToTree[parent]->right = node;
            else
                listToTree[parent]->left = node;
            
            head = head->next;
            pos++;
        }
    }
};
