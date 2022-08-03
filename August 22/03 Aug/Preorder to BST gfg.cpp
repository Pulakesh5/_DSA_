class Solution{
public:

 Node* solve(int pre[], int &index,
     		int min, int max, int &n) 
 {
        
    if(index >= n) return NULL;
        
    if(pre[index] < min || pre[index] > max)
          return NULL;
     Node* node = newNode(pre[index++]);
        
     node->left  = 
      solve(pre, index, min, node->data, n);
     node->right =
      solve(pre, index, node->data, max, n);
     return node;
  }

  Node* post_order(int pre[], int size) {
        
    int index = 0;
    int n = size;
        
   	return solve(pre, index, 0, INT_MAX, n);
 }

};
