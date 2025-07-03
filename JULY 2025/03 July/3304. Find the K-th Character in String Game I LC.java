class Solution {
    public char kthCharacter(int k) {
        StringBuilder sb = new StringBuilder();
        sb.append('a');
        int currLen = 1;
        char ch, next;
        while(currLen<k)
        {
            int len = sb.length();
            for(int i=0; i<len; i++)
            {
                next = (char)('a'+(sb.charAt(i)-'a'+1)%26);
                sb.append(next);
            } 
            currLen = sb.length();
        }
        return sb.charAt(k-1);
    }
}
