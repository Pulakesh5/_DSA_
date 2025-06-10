class Solution {
    int countStrings(String s) {
        // code here
        int[] charFreq = new int[26];
        int len = s.length();

        for(int i=0; i<len; i++)
        {
            charFreq[s.charAt(i)-'a']++;
        }
        int ans = 0;
        boolean repeat = false;
        for(int i=0; i<len; i++)
        {
            if(charFreq[s.charAt(i)-'a']>0)
            {
                ans += (len-charFreq[s.charAt(i)-'a']);
                // System.out.println((char)('a'+i)+" "+(len-charFreq[i])+" "+charFreq[i]+" ans = "+ans);
            }
            if(charFreq[s.charAt(i)-'a']>1)
                repeat = true;
            // charFreq[i] += charFreq[i-1];
        }
        ans/=2;
        
        return repeat?ans+1:ans;
    }
}
