/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* cloneGraph(Node* node) {
        map<Node*,Node*> mp;
        set<Node*> visited;
        queue<Node*> q;
        if(node)
            mp[node]= new Node(node->val);
        q.push(node);
        visited.insert(node);
        while(!q.empty())
        {
            Node* nd = q.front();
            q.pop();
            if(!nd) continue;

            for(auto next:nd->neighbors)
            {
                if(mp.find(next)==mp.end())
                    mp[next] = new Node(next->val);
                mp[nd]->neighbors.push_back(mp[next]);
                if(visited.find(next)==visited.end())
                {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
        return mp[node];
    }
};
