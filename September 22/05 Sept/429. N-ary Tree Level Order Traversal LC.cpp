/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> traversal;
        queue<Node*> q;
        if(root)
            q.push(root);
        vector<int> level;
        int qsize;
        while(!q.empty())
        {
            level.clear();
            qsize=q.size();
            for(int i=0;i<qsize;i++)
            {
                Node* frnt=q.front();
                q.pop();
                level.push_back(frnt->val);
                for(auto child:(frnt->children))
                    q.push(child);
            }
            traversal.push_back(level);
        }
        return traversal;
    }
};
