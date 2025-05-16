class Solution {
    public boolean check(String a, String b)
    {
        if(a.length()!=b.length())
            return false;
        int mismatch=0;
        for(int i=0; i<a.length(); i++)
        {
            if(a.charAt(i)!=b.charAt(i))
                mismatch++;
        }
        return mismatch==1;
    }
    public List<String> getWordsInLongestSubsequence(String[] words, int[] groups) {
        int N = words.length;
        int[] parent = new int[N];
        int[] dp = new int[N];
        Arrays.fill(dp, 1);
        Arrays.fill(parent, -1);

        int maxLen = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(groups[i]!=groups[j] && check(words[j], words[i]) && dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                }
            }
            if(dp[i]>maxLen)
                maxLen = dp[i];
        }

        List<String> longestSubsequence = new ArrayList<>();
        for(int i=0; i<N; i++)
        {
            if(dp[i]==maxLen)
            {
                while(i!=-1)
                {
                    longestSubsequence.add(words[i]);
                    i = parent[i];
                }
                break;
            }
        }
        Collections.reverse(longestSubsequence);
        return longestSubsequence;
    }
}
