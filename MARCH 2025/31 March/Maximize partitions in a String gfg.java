class Solution {
    public int maxPartitions(String s) {
        // code here
        int[] last = new int[26];
        int N = s.length();
        int i = 0;
        for(char ch:s.toCharArray())
            last[ch-'a'] = i++;
        
        int range=0, partition = 0;
        i = 0;
        for(char ch:s.toCharArray()) 
        {
            range = Math.max(range, last[ch-'a']);
            if(range == i)
            {
                range = i+1;
                partition++;
            }
            i++;
        }
        return partition;
    }
}
