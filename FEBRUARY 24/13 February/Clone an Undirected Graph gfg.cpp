class Solution {
public:
    map<int,Node*> cloneMapping;
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        
        if(cloneMapping.find(node->val)!=cloneMapping.end())
            return cloneMapping[node->val];
        
        int len = node->neighbors.size();
        
        Node* newNode = new Node(node->val);
        cloneMapping[node->val] = newNode;
        
        for(int i=0; i<len; i++)
        {
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return newNode;
    }
};
