// User function Template for Java
class Solution {
    public int findTarget(int arr[], int target) {
        // code here
        int N = arr.length, lptr = 0, rptr = N-1;
        int left, right, index;
        while(lptr<=rptr)
        {
            index = (lptr+rptr)/2;
            left = (index-1 < 0)? Integer.MIN_VALUE:arr[index-1];
            right = (index+1>=N) ? Integer.MAX_VALUE:arr[index+1];
            
            if(arr[index]==target)
                return index;
            
            if(target==left)
                return index-1;
            if(target==right)
                return index+1;
                
            else if(target>arr[index])
                lptr = index+1;
            else if(target<arr[index])
                rptr = index-1;
        }
        return -1;
    }
}
