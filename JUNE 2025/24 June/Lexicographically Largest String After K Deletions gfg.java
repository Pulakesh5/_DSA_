class Solution {
    public static String maxSubseq(String s, int k) {
        // code here
        Stack<Integer> stk = new Stack<>();
        int N = s.length();
        int count = 0;
        
        for(int i=0; i<N; i++)
        {
            while(count>(i-k) && !stk.empty() && s.charAt(stk.peek())<s.charAt(i))
            {
                count--;
                stk.pop();
            }
            
            if(count<(N-k))
            {
                stk.push(i);
                count++;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        while(!stk.isEmpty())
        {
            sb.append(s.charAt(stk.peek()));
            stk.pop();
        }
        return sb.reverse().toString();
    }
}
