class Solution {
    boolean checkSymmetry(Node left, Node right)
    {
        if(left==null && right==null)
            return true;
        
        if((left==null || right==null) || left.data!=right.data)
            return false;
        
        return checkSymmetry(left.right, right.left) && checkSymmetry(left.left, right.right);
    }
    
    public boolean isSymmetric(Node root) {
        // Code here
        return checkSymmetry(root.left, root.right);
    }
}
