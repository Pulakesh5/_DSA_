class Solution {
    boolean breakString(String s, Set<String> words, int l, int r, int[] dp)
    {
        int length = s.length();
        if(l>=length)
            return true;
        
        if(dp[l]!=-1)
            return (dp[l]==1);

        StringBuilder sb = new StringBuilder();
        for(int i=l; i<=r; i++)
        {
            sb.append(s.charAt(i));
            if(words.contains(sb.toString()) && breakString(s, words, i+1, r, dp))
            {
                dp[l] = 1;
                return true;
            }
        }
        dp[l] = 0;
        return false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<String>(wordDict);
        int length = s.length();
        int[] dp = new int[length+1];
        Arrays.fill(dp,-1);
        return breakString(s, words, 0, length-1, dp);
    }
}
