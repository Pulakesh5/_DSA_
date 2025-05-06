class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int length = s.length();
        boolean[] possible = new boolean[length+1];
        Set<String> words = new HashSet<String>(wordDict);
        possible[0] = true;
        for(int j=1; j<=length; j++)
        {
            for(int i=0; i<j; i++)
            {
                if(possible[i] && words.contains(s.substring(i,j)))
                {
                    possible[j] = true;
                    break;
                }
            }
        }
        return possible[length];
    }
}
