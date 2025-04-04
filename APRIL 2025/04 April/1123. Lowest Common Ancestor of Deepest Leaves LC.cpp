/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    class Pair{
        int height;
        TreeNode node;
        public Pair(int h, TreeNode n) {
            this.height = h;
            this.node = n;
        }
    }
    public Pair helper(TreeNode root) {
        if(root == null)
            return new Pair(0,null);
        
        Pair left = helper(root.left);
        Pair right = helper(root.right);

        if(left.height > right.height)
            return new Pair(left.height+1, left.node);
        if(left.height < right.height)
            return new Pair(right.height+1, right.node);
        
        return new Pair(right.height+1, root);
    }
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return helper(root).node;
    }
}
