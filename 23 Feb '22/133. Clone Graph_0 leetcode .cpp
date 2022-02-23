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

//BFS solution
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        Node* deepClone = new Node(node->val,{});
        mp[node]=deepClone;
        
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* cur=q.front();
            q.pop();
            for(auto it:cur->neighbors){
                if(mp.find(it)==mp.end()){
                    mp[it]=new Node(it->val, {});
                    q.push(it);
                }
                mp[cur]->neighbors.push_back(mp[it]);
            }
        }
        return deepClone;
    }
private:
    unordered_map<Node*,Node*> mp; //original->fake(key->value)
};
