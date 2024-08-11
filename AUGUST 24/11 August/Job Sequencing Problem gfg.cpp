bool comp(Job job1, Job job2)
{
    return job1.profit>job2.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int currTime = 0, N = n;
        sort(arr, arr+N, comp);
        int totalProfit = 0, count=0;
        bool done[N]= {false};
        for(int i=0; i<N; i++)
        {
            for(int j=arr[i].dead-1; j>=0; j--)
            {
                if(done[j]==0)
                {
                    done[j] = 1;
                    totalProfit += arr[i].profit;
                    count++;
                    break;
                }
            }
        }
        vector<int> result;
        result.push_back(count);
        result.push_back(totalProfit);
        return result;
    } 
};
