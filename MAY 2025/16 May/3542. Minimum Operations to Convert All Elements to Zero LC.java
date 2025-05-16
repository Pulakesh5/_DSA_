class Solution {
    public int minOperations(int[] nums) {
        Deque<Integer> q = new ArrayDeque<>();
        boolean[] visited = new boolean[100005];
        int operation = 0, N = nums.length;
        for(int i=0; i<N; i++)
        {
            int num = nums[i];

            if(num==0) // discard all previous elements
            {
                while(q.size()>0)
                {
                    visited[q.pollLast()] = false;
                }
                continue;
            }

            while(q.size()>0 && q.peekLast()>num)
            {
                visited[q.peekLast()] = false;
                q.pollLast();
            }
            
            if(!visited[num])
            {
                operation++;
                visited[num] = true;
            }
            q.offer(num);

        }
        return operation;
    }
}
