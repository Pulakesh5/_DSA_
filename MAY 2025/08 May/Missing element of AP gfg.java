class Solution {
    public int findMissing(int[] arr) {
        // code here
        int n = arr.length;
        if(n==2)
            return 2*arr[1]-arr[0];
            
        int diff = arr[1]-arr[0];
        
        for(int i=2; i<n; i++)
        {
            if(arr[i]-arr[i-1]!=diff)
                return arr[i]-diff;
        }
        return arr[n-1]+diff;
    }
}
