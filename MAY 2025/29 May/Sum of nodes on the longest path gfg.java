class Solution {
    private int longestPathSum, longestPathLength;
    public void traverse(Node root, int currLength, int currSum)
    {
        if(root == null)
        {
            if(currLength>longestPathLength)
            {
                longestPathLength = currLength;
                longestPathSum = currSum;
            }
            else if(currLength==longestPathLength)
                longestPathSum = Math.max(longestPathSum, currSum);
            return;
        }
        
        traverse(root.left, currLength+1, currSum+root.data);
        traverse(root.right, currLength+1, currSum+root.data);
    }
    public int sumOfLongRootToLeafPath(Node root) {
        // code here
        longestPathLength = 0;
        longestPathSum = 0;
        
        traverse(root, 0, 0);
        
        return longestPathSum;
    }
}
