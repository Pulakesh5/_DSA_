class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        int in_l = 0, in_r = n-1;
        int post_l = 0, post_r = n-1;
        return makeTree(in, post, in_l, in_r, post_l, post_r);
    }
    private: 
    Node* makeTree(int in[], int post[], int in_l, int in_r, int post_l, int post_r)
    {
        if(in_r<in_l)
            return nullptr;
        if(in_r==in_l)
        {
            return new Node(in[in_r]);
        }
        int root = post[post_r], index;
        for(int i=in_l; i<=in_r; i++)
        {
            if(in[i]==root)
            {
                index = i;
                break;
            }
        }
        
        int lTreeSize = (index-in_l);
        int rTreeSize = (in_r-index);
        
        Node* rootNode = new Node(in[index]);
        
        rootNode->left = makeTree(in, post, in_l, index-1, post_l, post_l+lTreeSize-1);
        rootNode->right = makeTree(in, post, index+1, in_r, post_r-rTreeSize, post_r-1);
        
        return rootNode;
    }
};
