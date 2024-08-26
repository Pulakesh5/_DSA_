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
    vector<int> postorder(Node* root) {
        stack<pair<Node*, bool>> stk; // {node, flag}
        if(root == nullptr)
            return {};
        vector<int> traversal;
        stk.push({root, false});
        while(!stk.empty())
        {
            auto pr = stk.top();
            stk.pop();
            if(pr.second)
            {
                traversal.push_back(pr.first->val);
                continue;
            }

            pr.second = true;
            stk.push(pr);
            vector<Node*> children = pr.first->children;
            for(int i=children.size()-1; i>=0; i--)
            {
                stk.push({children[i], false});
            }
        }
        return traversal;
    }
};
