class Solution {
    public int possibleStringCount(String word, int k) {
        if(word.isEmpty())
            return 0;
        
        List<Integer> charCounts = new ArrayList<>();
        int count = 1, N = word.length();
        for(int i=1; i<N; i++)
        {
            if(word.charAt(i)==word.charAt(i-1))
                count++;
            else
            {
                charCounts.add(count);
                count = 1;
            }
        }
        charCounts.add(count);

        int MOD = (int)(1e9+7);
        long total = 1;
        for(int cnt:charCounts)
            total = (total*cnt)%MOD;
        
        if(k<=charCounts.size())
            return (int)total;

        int[] dp = new int[k];
        dp[0] = 1;
        for(int cnt:charCounts)
        {
            int[] newDp = new int[k];
            long sum = 0;
            for(int i=1; i<k; i++)
            {
                if(i>0)
                    sum = (sum+dp[i-1])%MOD;
                if(i>cnt)
                    sum = (sum - dp[i-cnt-1] + MOD)%MOD;
                newDp[i] = (int) sum;
            }
            dp = newDp;
        }

        long invalidStringCount = 0;
        for(int i=charCounts.size(); i<k; i++)
            invalidStringCount = (invalidStringCount + dp[i])%MOD;
        
        return (int)((total-invalidStringCount+MOD)%MOD);
    }
}
