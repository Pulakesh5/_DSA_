class Solution{
public:
struct Node{
  Node *nodes[26];  
};

void insert(Node* node, string s){
    Node* root = node;
    for(auto& c: s){
        if(root->nodes[c-'a'] == NULL){
            root->nodes[c-'a'] = new Node();
        }
        root = root->nodes[c-'a'];
    }
}

bool search(Node* node, string s){
    Node* root = node;
    for(auto& c: s){
        if(root->nodes[c-'a'] == NULL) return false;
        root = root->nodes[c-'a'];
    }
    return true;
}
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        Node* root = new Node();
        for(auto& s: s1){
            insert(root, s);
            reverse(s.begin(), s.end());
            insert(root, s);
        }
        int ans = 0;
        for(auto& s: s2){
           string r = s;
           reverse(r.begin(), r.end());
           if(search(root, s) || search(root, r)) ans++;
        }
        return ans;
    }
};
