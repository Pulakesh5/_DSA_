class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        int NODE = colors.length();
        int EDGE = edges.length;
        int[] indegree = new int[NODE];
        int[][] charCount = new int[NODE][26];
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();

        for(int i=0; i<NODE; i++)
        {
            adjList.add(new ArrayList<>());
        }

        for(int i=0; i<EDGE; i++)
        {
            indegree[edges[i][1]]++;
            adjList.get(edges[i][0]).add(edges[i][1]);
        }

        Queue<Integer> q = new LinkedList<>();
        for(int i=0; i<NODE; i++)
        {
            if(indegree[i]==0)
            {
                q.offer(i);
                charCount[i][colors.charAt(i)-'a']++;
            }
        }

        int visited = 0;
        int answer = 0;
        while(!q.isEmpty())
        {
            int qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                int node = q.poll();
                for(int j=0; j<26; j++)
                    answer = Math.max(charCount[node][j], answer);
                visited++;
                for(int next:adjList.get(node))
                {
                    indegree[next]--;
                    for(int j=0; j<26; j++)
                            charCount[next][j] = Math.max(charCount[next][j],  charCount[node][j]);
                    if(indegree[next]==0)
                    {
                        q.offer(next);
                        charCount[next][colors.charAt(next)-'a']++;
                    }
                }
            }
        }

        if(visited!=NODE)
            return -1;

        return answer;
    }
}
