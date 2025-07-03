class Solution {
    public int longestKSubstr(String s, int k) {
        // code here
        Map<Character,Integer> charCount = new HashMap<>();
        int LEN = s.length(), maxLen = -1;
        char ch;
        for(int right=0,left=0; right<LEN; right++)
        {
            ch = s.charAt(right);
            charCount.put(ch, charCount.getOrDefault(ch,0)+1);
            while(charCount.size() > k)
            {
                ch = s.charAt(left);
                if(charCount.get(ch)==1)
                    charCount.remove(ch);
                else
                    charCount.put(ch, charCount.get(ch)-1);
                left++;
            }
            
            if(charCount.size()==k)
                maxLen = Math.max(maxLen, right-left+1);
        }
        return maxLen;
    }
}
