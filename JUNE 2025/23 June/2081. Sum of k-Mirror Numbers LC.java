class Solution {
    public long kMirror(int k, int n) {
        long kMirrorSum = 0L;

        for(int len=1; ;len++)
        {
            long low = (long)Math.pow(10,(len-1)/2);
            long high = (long)Math.pow(10,(len+1)/2);

            for(long num=low; num<high; num++)
            {
                long palindrome = num;
                for(long rev=(len%2==0)?num:num/10; rev>0; rev/=10)
                {
                    palindrome = palindrome*10 + rev%10;
                }

                String kBaseRep = Long.toString(palindrome, k);

                if(isPalindrome(kBaseRep.toCharArray()))
                {
                    kMirrorSum += palindrome;
                    if(--n == 0)
                        return kMirrorSum;
                }
            }
        }
    }

    private boolean isPalindrome(char[] str)
    {
        for(int left=0, right=str.length-1; left<right; left++, right--)
        {
            if(str[left]!=str[right])
                return false;
        }
        return true;
    }
}
