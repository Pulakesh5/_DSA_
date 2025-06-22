class Solution {
    public ArrayList<Integer> largestSubset(int[] arr) {
        // code here
        Arrays.sort(arr);
        int N = arr.length;
        for(int i=0, j=N-1; i<j; i++, j--)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        int[] dp = new int[N], lds = new int[N];
        for(int i=0; i<N; i++)
        {
            dp[i] = 1;
            lds[i] = -1;
        }
        
        int maxLen = 1, lastIndex = 0;
        for(int currIndex=1; currIndex<N; currIndex++)
        {
            // System.out.println(currIndex+" "+arr[currIndex]);
            for(int prev=0; prev<currIndex; prev++)
            {
                if(arr[prev]%arr[currIndex]==0 && dp[prev]+1>dp[currIndex])
                {
                    // System.out.print(prev+" "+arr[prev]+" dp:"+dp[prev]+"\t");
                    dp[currIndex] = dp[prev] + 1;
                    lds[currIndex] = prev;
                }
            }
            // System.out.println();
            
            if(dp[currIndex]>maxLen)
            {
                maxLen = dp[currIndex];
                lastIndex = currIndex;
            }
        }
        
        ArrayList<Integer> subset = new ArrayList<>();
        while(lastIndex>=0)
        {
            subset.add(arr[lastIndex]);
            lastIndex = lds[lastIndex];
        }
        // subset.add(arr[lastIndex]);
        // Collections.reverse(subset);
        
        return subset;
    }
}
