class Solution {
    public char low(int[] freq)
    {
        for(int i=0; i<26; i++)
        {
            if(freq[i]!=0)
                return (char)('a'+i);
        }
        return 'a';
    }
    public String robotWithString(String s) {
        Stack<Character> stk = new Stack<>();
        StringBuilder sb = new StringBuilder();
        int[] freq = new int[26];

        for(char ch:s.toCharArray())
            freq[ch-'a']++;
        
        for(char ch:s.toCharArray())
        {
            stk.push(ch);
            freq[ch-'a']--;
            while(!stk.isEmpty() && stk.peek()<=low(freq))
            {
                sb.append(stk.pop());
            }
        }

        while(!stk.isEmpty())
        {
            sb.append(stk.pop());
        }

        return sb.toString();
    }
}
