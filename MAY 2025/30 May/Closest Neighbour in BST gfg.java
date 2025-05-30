class Solution {
    public int findMaxFork(Node root, int k) {
        // code here.
        if(root == null)
            return -1;
            
        if(root.data<=k)
            return Math.max(root.data, findMaxFork(root.right, k));
        else
            return findMaxFork(root.left, k);
    }
}
