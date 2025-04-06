class Solution {
    public String minWindow(String s, String t) {
        if(s.length()<t.length())
            return "";
        int[] t_freq = new int[60], window_freq = new int[60];

        for(char t_char:t.toCharArray())
            t_freq[t_char-'A']++;

        int N = s.length(), match = 0, index;
        int window_left=0, window_right=-1, window_size = N+5;

        for(int left=0, right=0; right<N; right++) {
            index = s.charAt(right)-'A';
            window_freq[index]++;
            
            if(window_freq[index]<=t_freq[index])
                match++;
            if(match < t.length())    
                continue; // this is a optimization, which starts moving left pointer only after capturing t string equivalent window

            index = s.charAt(left)-'A';
            while(left<=right && window_freq[index]>t_freq[index])
            {
                left++;
                if(left>right)
                {
                    left--;
                    break;
                }
                window_freq[index]--;
                index = s.charAt(left)-'A';
            }
            System.out.println(left+" "+right);
            if((right-left+1)<window_size)
            {
                window_size = (right-left+1);
                window_left = left;
                window_right = right; 
                System.out.println(window_left+" "+window_right);
            }
        }
        return s.substring(window_left, window_right+1);
    }
}
