class Solution {
    // Function to find the largest number after k swaps.
    static String maxNumber;
    public static void swap(char[] s, int i, int j)
    {
        if(i==j)
            return;
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    public static void findMax(char[] num, int index, int k)
    {
        if(k==0 || index==num.length)
            return;
        char maxDigit = num[index];
        for(int i=index+1; i<num.length; i++)
        {
            if(num[i]>maxDigit)
                maxDigit = num[i];
        }
        
        if(maxDigit!=num[index])
            k--;
        
        for(int i=num.length-1; i>=index; i--)
        {
            if(num[i]==maxDigit)
            {
                swap(num, index, i);
                String current = new String(num);
                if(current.compareTo(maxNumber)>0)
                    maxNumber = current;
                
                findMax(num, index+1, k);
                
                swap(num, index, i);
            }
        }
    }
    public String findMaximumNum(String s, int k) {
        // code here.
        maxNumber = s;
        findMax(s.toCharArray(), 0, k);
        return maxNumber;
    }
}
