//User function Template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
return 0 -> if it has vaccine
return 1 -> any of its child have vaccine
return -1 -> it needs vaccine
it is a DFS solution
*/
class Solution{
public:
    int vaccine=0;
    int helper(Node *root){
        if(!root) return 1;
        int lt=helper(root->left);
        int rt=helper(root->right);
        if(lt==-1 || rt==-1)
        {
            vaccine++;
            return 0;
        }
        if(lt==0 || rt==0)
            return 1;
        return -1;
    }
    int supplyVaccine(Node* root){
        if(helper(root)==-1)
            vaccine++;
        return vaccine;
    }
};
