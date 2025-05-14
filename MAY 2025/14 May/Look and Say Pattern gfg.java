class Solution {
    public String process(String s, int n)
    {
        if(n==1)
            return s;
            
        StringBuilder sb = new StringBuilder();
        int Len = s.length(), i=0;
        while(i<Len)
        {
            int j=i;
            while(j<Len && s.charAt(i)==s.charAt(j))
                j++;
            sb.append(Integer.toString(j-i));
            sb.append(s.charAt(i));
            i=j;
        }
        return process(sb.toString(), n-1);
    }
    public String countAndSay(int n) {
        // code here
        return process("1", n);
    }
}
