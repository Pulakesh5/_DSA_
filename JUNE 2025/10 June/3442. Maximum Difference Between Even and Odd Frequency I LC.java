class Solution {
    public int maxDifference(String s) {
        int[] charFreq = new int[26];
        
        for(char ch:s.toCharArray())
        {
            charFreq[ch-'a']++;
        }

        int ans = Integer.MIN_VALUE;
        for(int i=0; i<26; i++)
        {
            for(int j=i+1; j<26; j++)
            {
                if(charFreq[i]>0 && charFreq[j]>0){
                    if(charFreq[i]%2==1 && charFreq[j]%2==0)
                        ans = Math.max(ans, charFreq[i]-charFreq[j]);
                    else if(charFreq[i]%2==0 && charFreq[j]%2==1)
                        ans = Math.max(ans, charFreq[j]-charFreq[i]);
                }
            }
        }

        return ans;
    }
}
