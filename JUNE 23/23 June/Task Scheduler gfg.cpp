class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        vector<int> taskCount(26,0);
        int maxFreq = 0;
        for(char task:tasks)
        {
            taskCount[task-'A']++;
            maxFreq = max(maxFreq, taskCount[task-'A']);
        }
        int maxFreqCount = 0;
        sort(taskCount.begin(), taskCount.end(), greater<int>());
        for(int i=0; i<26; i++){
            if((taskCount[i] == maxFreq))
                maxFreqCount++;
        }
        // cout<<maxFreq<<" "<<maxFreqCount<<endl;
        return max(N, ((maxFreq-1)*K + (maxFreq-1) + maxFreqCount));
        
    }
};
