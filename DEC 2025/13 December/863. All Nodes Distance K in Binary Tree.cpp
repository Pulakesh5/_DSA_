/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void propagateDistance(TreeNode* node, int K, int distance, vector<int> &kDistanceNodes) {
        if(node==NULL) return;
        if(distance==K) {
            kDistanceNodes.push_back(node->val);
            return;
        }
        propagateDistance(node->left, K, distance+1, kDistanceNodes);
        propagateDistance(node->right, K, distance+1, kDistanceNodes);
    }
    int dfs(TreeNode* node, TreeNode* target, int K, vector<int> &kDistanceNodes) { // returns distance from target or -1 if does not contain target in the subtree
        if(node == NULL)
            return -1;
        
        if(node==target) {
            propagateDistance(node, K, 0, kDistanceNodes);
            return 0;
        }

        int lDistance = dfs(node->left, target, K, kDistanceNodes);
        if(lDistance!=-1) { // leftsubtree ccontains target node 
            if(lDistance+1 == K) {
                kDistanceNodes.push_back(node->val); // if current node is at distance K from the child target node
            } else {
                propagateDistance(node->right, K, lDistance+2, kDistanceNodes); // propagate distance in the right subtree through current node
            }
            return lDistance+1; // send the current node's distance to parent
        }

        int rDistance = dfs(node->right, target, K, kDistanceNodes);
        if(rDistance!=-1) { // rightsubtree ccontains target node 
            if(rDistance+1 == K) {
                kDistanceNodes.push_back(node->val); // if current node is at distance K from the child target node
            } else {
                propagateDistance(node->left, K, rDistance+2, kDistanceNodes); // propagate distance in the left subtree through current node
            }
            return rDistance+1; // send the current node's distance to parent
        }

        // if reached here target node was not found in this subtree so return -1
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> kDistanceNodes;
        dfs(root, target, k, kDistanceNodes);
        return kDistanceNodes;
    }
};
