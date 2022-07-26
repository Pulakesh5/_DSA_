int match(Node *p1, Node*p2){
    int length=0;
    while(p1 && p2 && p1->data==p2->data)
    {
        length+=2;
        p1=p1->next;
        p2=p2->next;
    }
    return length;
}
int maxPalindrome(Node *head)
{

    Node *curr=head,*prev=NULL, *next;
    int oddLength=0,evenLength=1;
    while(curr->next){
        next=curr->next;
        curr->next=prev;
        
        evenLength=max(evenLength,match(curr,next));
        oddLength=max(oddLength,1+match(prev,next));
        
        prev=curr;
        curr=next;
    }
    
    return max(oddLength, evenLength);
}
/*****************************************************************************/*****************************************************************************/

    int match(vector<int> &vec, int i, int j){
    int n=vec.size(), count=0;
    while(i>=0 && j<n && vec[i]==vec[j]){
        count+=2;
        i--;
        j++;
    }
    return count;
}
int maxPalindrome(Node *head)
{
    //Your code here
    Node *curr=head;
    vector<int> vec;
    while(curr){
        vec.push_back(curr->data);
        curr=curr->next;
    }
    
    int oddLength=1,evenLength=0,n=vec.size();
    for(int i=0;i<n;i++){
        oddLength = max(oddLength,1+match(vec,i-1,i+1));
        evenLength = max(evenLength,match(vec,i,i+1));
    }
    
    return max(oddLength, evenLength);
}
