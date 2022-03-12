/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        Node* ans=new Node(head->val),*ptr;;
        unordered_map<Node*,Node*> mp;
        mp[head]=ans;
        Node* _head=ans;
        
        while(head){
            if(head->next && mp.find(head->next)==mp.end()){
                ptr= new Node(head->next->val);
                mp[head->next]=ptr;
            }
            ans->next=mp[head->next];
            if(head->random && mp.find(head->random)==mp.end()){
                ptr= new Node(head->random->val);
                mp[head->random]=ptr;
            }
            ans->random=mp[head->random];
            
            head=head->next;   
            ans=ans->next;
        }
        return _head;
        
    }
};
