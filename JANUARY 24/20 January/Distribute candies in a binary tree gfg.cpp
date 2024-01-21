//User function Template for C++

/*
struct Node {
	int key;
	Node *left, *right;
};
*/

class Solution
{
    public:
    int solve(Node* root, int &moves)
    {
        if(root==nullptr)
            return 0;
        int leftTree = solve(root->left, moves);
        int rightTree = solve(root->right, moves);
        moves+=(abs(leftTree)+abs(rightTree));
        return (root->key+(leftTree+rightTree)-1);
    }
    int distributeCandy(Node* root)
    {
        //code here
        int moves=0;
        solve(root, moves);
        return moves;
    }
};
