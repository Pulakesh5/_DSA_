class Solution {
  public:
    vector<int> diagonalSum(Node* root) {
        // Add your code here
        vector<int> diagonalSums;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int qsize = q.size();
            int sum = 0;
            for(int i=0; i<qsize; i++)
            {
                Node* node = q.front();
                q.pop();
                sum = sum + node->data;
                while(node)
                {
                    if(node->right)
                        sum += (node->right->data);
                    if(node->left)
                        q.push(node->left);
                    node = node->right;
                }
            }
            diagonalSums.push_back(sum);
        }
        return diagonalSums;
    }
};
