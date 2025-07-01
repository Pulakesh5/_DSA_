class Solution {
    public int substrCount(String s, int k) {
        // code here
        int N = s.length();
        int[] windowFreq = new int[26];
        int countOfDuplicate = 0, ch;
        for(int i=0; i<Math.min(N, k); i++)
        {
            ch = s.charAt(i)-'a';
            windowFreq[ch]++;
        }
        
        for(int i=0; i<26; i++)
        {
            if(windowFreq[i]>1)
                countOfDuplicate+=windowFreq[i];
        }
        int countOfSubstr = (countOfDuplicate == 2? 1: 0);
        for(int i=k; i<N; i++)
        {
            ch = s.charAt(i)-'a';
            // if(windowFreq[ch]==1)
            //     countOfDuplicate++;
            windowFreq[ch]++; // move right end of window 
            
            ch = s.charAt(i-k)-'a';
            // if(windowFreq[ch]==2)
            //     countOfDuplicate--;
            windowFreq[ch]--; // move left end of window
            
            countOfDuplicate = 0;
            for(int j=0; j<26; j++)
            {
                if(windowFreq[j]>1)
                    countOfDuplicate += windowFreq[j];
            }

            // System.out.println("Index "+i+" dupCount = "+countOfDuplicate+" strCount = "+countOfSubstr);
            countOfSubstr += (countOfDuplicate == 2? 1: 0);
        }
        
        return countOfSubstr;
    }
}
