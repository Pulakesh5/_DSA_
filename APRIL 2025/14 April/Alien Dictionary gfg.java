class Solution {
    public String findOrder(String[] words) {
        // code here
        Map<Character, List<Character>> adj = new HashMap<>();
        Map<Character, Integer> indegree = new HashMap<>();
        
        for(String word:words)
        {
            for(char c:word.toCharArray())
            {
                adj.putIfAbsent(c, new ArrayList<>());
                indegree.putIfAbsent(c, 0);
            }
        }
        
        int N = words.length;
        char char1, char2;
        
        for(int i=0; i<(N-1); i++)
        {
            String word1 = words[i], word2 = words[i+1];
            int minLen = Math.min(word1.length(), word2.length());
            boolean mismatch = false;
            for(int k=0; k<minLen; k++)
            {
                char1 = word1.charAt(k);
                char2 = word2.charAt(k);
                if(char1 != char2)
                {
                    adj.get(char1).add(char2);
                    indegree.put(char2, indegree.get(char2)+1);
                    mismatch = true;
                    break;
                }
            }
            
            if(!mismatch && word1.length() > word2.length()) // word2 is a prefix of word1
            {
                return "";
            }
        }
        
        Queue<Character> q = new ArrayDeque<>();
        int uniqueChar = 0;
        for(char ch:indegree.keySet())
        {
            if(indegree.get(ch)==0)
                q.add(ch);
        }
        
        StringBuilder sb = new StringBuilder();
        while(!q.isEmpty())
        {
            char node = q.poll();
            sb.append(node);
            for(char next:adj.get(node))
            {
                indegree.put(next, indegree.get(next)-1);
                if(indegree.get(next)==0)
                    q.offer(next);
            }
        }
        // cycle exists
        if(sb.toString().length()!=indegree.size())
        {
            return "";
        }
        // System.out.println(sb.toString());
        return sb.toString();
    }
}
