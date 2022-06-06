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
//DFS Solution
class Solution {
private:
    unordered_map<Node*, Node*> copy;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(copy.find(node)==copy.end()){
            copy[node]=new Node(node->val,{});
            for(auto nodes:node->neighbors){
                copy[node]->neighbors.push_back(cloneGraph(nodes));
            }
        }
        
        return copy[node];
    }
};
//BFS Solution
class Solution {
private:
    unordered_map<Node*, Node*> copy;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        copy[node]= new Node(node->val, {});
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            
            for(auto nodes:curr->neighbors){
                if(copy.find(nodes)==copy.end()){
                    copy[nodes] = new Node(nodes->val, {});
                    q.push(nodes);
                }
                copy[curr]->neighbors.push_back(copy[nodes]);
            }
        }
        
        return copy[node];
    }
};
