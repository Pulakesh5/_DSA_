class Solution{
    private:
    TNode* postorder(vector<int> &arr, int start, int end){
        if(start>end)
            return NULL;
        int mid=start+(end-start)/2;
        if((start+end)&1) mid++;
        TNode *node = new TNode(arr[mid]);
        node->left=postorder(arr, start, mid-1);
        node->right=postorder(arr,mid+1,end);
        return node;
    }
    
  public:
    TNode* sortedListToBST(LNode *head) {
        vector<int> arr;
        LNode *ptr=head;
        while(ptr){
            arr.push_back(ptr->data);
            ptr=ptr->next;
        }
        int n=arr.size();
        return postorder(arr,0,n-1);
    }
};
