struct Node* partition(struct Node* head, int x) {
    vector<int> lesser,equal,greater;
    
    Node *node=head;
    while(node){
        if(node->data<x) lesser.push_back(node->data);
        else if(node->data==x) equal.push_back(node->data);
        else greater.push_back(node->data);
        node = node->next;
    }
    node=head;
    
    int l=lesser.size(),e=equal.size(),g=greater.size();
    int i=0;
    while(i<l){
        node->data=lesser[i++];
        node=node->next;
    }
    i=0;
    while(i<e){
        node->data=equal[i++];
        node=node->next;
    }
    i=0;
    while(i<g){
        node->data=greater[i++];
        node=node->next;
    }
    return head;
}
