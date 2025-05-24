class Solution {
    public static int contribution(int digit, int index, int N)
    {
        int pow = 0, exp=1;
        for(int i=0; i<(N-index); i++)
        {
            pow += exp;
            exp = exp*10;
        }
        
        int _contribution = (index+1)*digit*pow;
        
        // System.out.println(digit+" "+_contribution+" "+pow);
        
        return _contribution;
    }
    public static int sumSubstrings(String s) {
        // code here
        // main observation is that 
        // [assume length of string is N]
        // any digit at index i will contribute d*(i+1)*[10^0+10^1+..+10^(N-i)] to the final answer
        int sumOfAllSubstrings = 0;
        int N = s.length(); 
        for(int i=0; i<N; i++)
        {
            sumOfAllSubstrings += contribution(s.charAt(i)-'0', i, N);
        }
        return sumOfAllSubstrings;
    }
}
