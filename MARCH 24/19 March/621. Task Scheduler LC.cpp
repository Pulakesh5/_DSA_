class Solution {
public:
    int leastInterval(vector<char>& tasks, int coolingPeriod) {
        vector<int> taskFreq(26,0);
        int maxFreq = 0;
        for(auto task:tasks)
        {
            taskFreq[task-'A']++;
            maxFreq = max(maxFreq, taskFreq[task-'A']);
        }
        int timeInterval = (maxFreq-1)*(coolingPeriod+1);
        for(int i=0; i<26; i++)
        {
            if(taskFreq[i]==maxFreq)
                timeInterval++;
        }
        return max(timeInterval,(int)tasks.size());
        // vector<int> lastTask(26,-100007);
        // int remainingTask = tasks.size();
        // for(char task:tasks)
        //     taskFreq[task-'A']++;
        // int timeInterval=0;
        // int mostRemainingTaskFreq, mostRemainingTask;
        // int earliestNext, earliestNextTask;
        // while(remainingTask--)
        // {
        //     mostRemainingTaskFreq = 0;
        //     earliestNext = INT_MAX;
        //     for(int i=0; i<26; i++)
        //     {
        //         if(taskFreq[i])
        //         {
        //             if(taskFreq[i]>mostRemainingTaskFreq)
        //             {
        //                 mostRemainingTaskFreq = taskFreq[i];
        //                 mostRemainingTask = i;
        //             }
        //             if(lastTask[i]+coolingPeriod<earliestNext)
        //             {
        //                 earliestNext = lastTask[i]+coolingPeriod;
        //                 earliestNextTask = i;
        //             }
        //         }
        //     }
        //     // cout<<mostRemainingTask<<" "<<earliestNextTask<<endl;
        //     if(lastTask[mostRemainingTask]+coolingPeriod <= timeInterval)
        //     {
        //         taskFreq[mostRemainingTask]--;
        //         timeInterval++;
        //         // cout<<timeInterval<<" : "<<(char)('A'+mostRemainingTask)<<endl;
        //         lastTask[mostRemainingTask] = timeInterval;
        //     }
        //     else
        //     {
        //         timeInterval = max(earliestNext,timeInterval)+1;
        //         taskFreq[earliestNextTask]--;
        //         // cout<<timeInterval<<" : "<<(char)('a'+earliestNextTask)<<endl;
        //         lastTask[earliestNextTask] = timeInterval;
        //     }
        // }
        // return timeInterval;
    }
};

//  A B A C A D A E A F A G
