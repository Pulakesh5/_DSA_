class Solution {
    long res = 0;
    Set<String> visited = new HashSet<>();

    long arrToNumber(int[] digits)
    {
        long num = 0;
        for(int d:digits)
            num = num*10+d;
        return num;
    }
    long factorial(int n) {
        long res = 1;
        for(int i=2; i<=n; i++)
            res *= i;
        return res;
    }
    long totalPermutations(Map<Integer, Integer> freq, int len)
    {
        long res = factorial(len); // n!
        for(int count:freq.values())
            res/=factorial(count); // n!/(n1! * n2! * n3! ...)
        return res;
    }

    long permsWithZero(Map<Integer,Integer> freq, int len) {
        if(!freq.containsKey(0) || freq.get(0)==0)
            return 0;
        freq.put(0, freq.get(0)-1);
        long res = factorial(len-1);
        for(int count:freq.values())
            res = res/factorial(count);
        return res;
    }
    
    void generatePalindrome(int[] palindrome, int left, int right, int divisor, int len)
    {
        if(left>right) 
        {
            long val = arrToNumber(palindrome);
            if(val % divisor == 0)
            {
                Map<Integer, Integer> freq = new HashMap<>();
                for(int d:palindrome)
                    freq.put(d, freq.getOrDefault(d,0)+1);
                
                String key = freq.toString();
                if(!visited.contains(key))
                {
                    res += (totalPermutations(freq, len) - permsWithZero(new HashMap<>(freq), len));
                    visited.add(key);
                }
            }
            return;
        }

        for(int d=(left==0 ? 1:0); d<=9; d++)
        {
            palindrome[left] = palindrome[right] = d;
            generatePalindrome(palindrome, left+1, right-1, divisor, len);
        }
    }
    public long countGoodIntegers(int n, int k) {
        res = 0;
        visited.clear();
        generatePalindrome(new int[n], 0, n-1, k, n);
        return res;
    }
}
