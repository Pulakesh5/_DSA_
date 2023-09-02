class Solution
{
public:
    int getCount(Node *root, int k)
    {
        //code here
        queue<Node*> q;
        q.push(root);
        Node* node;
        int level = 1, count = 0, qs;
        while(!q.empty())
        {
            qs = q.size();
            for(int i=0; i<qs; i++)
            {
                node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                if(!(node->left) && !(node->right) && k>=level)
                    count++, k-=level;
            }
            level++;
        }
        return count;
    }
};
