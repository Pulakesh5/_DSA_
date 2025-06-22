class Solution {
    public String[] divideString(String s, int k, char fill) {
        StringBuilder sb = new StringBuilder();
        int N = s.length();
        int N_Strings = (N+k-1)/k;
        String[] dividedStrings = new String[N_Strings];
        for(int i=0, j=0; i<N; i++)
        {
            sb.append(s.charAt(i));
            if((i+1)%k==0)
            {
                dividedStrings[j++] = sb.toString();
                sb.setLength(0);
            }
            System.out.println(i+" "+sb.toString());
        }
        
        while(sb.length()!=0 && sb.length()<k)
            sb.append(fill);
        
        if(sb.length()!=0)
            dividedStrings[N_Strings-1] = sb.toString();

        return dividedStrings;
    }
}
