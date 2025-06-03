class Solution {
    int countSubstrWithAtmostKChar(String s, int k)
    {
        
        HashMap<Character, Integer> charCount = new HashMap<>();
        int left = 0, right=0, N = s.length();
        char ch;
        int countOfSubstr = 0;
        while(right<N)
        {
            ch = s.charAt(right);
            charCount.put(ch, charCount.getOrDefault(ch,0)+1);
            
            while(charCount.size()>k)
            {
                ch = s.charAt(left);
                if(charCount.get(ch)==1)
                    charCount.remove(ch);
                else
                    charCount.put(ch, charCount.get(ch)-1);
                left++;
            }
            right++;
            
            countOfSubstr += (right-left+1);
        }
        return countOfSubstr;
    }
    int countSubstr(String s, int k) {
        // your code here
        return countSubstrWithAtmostKChar(s, k) - countSubstrWithAtmostKChar(s, k-1);
    }
}
