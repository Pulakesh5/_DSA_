class Solution {
  public:
  
    bool check(vector<int> &pages, int N, int K, int threshold)
    {
        int total=0, student=1;
        for(int i=0; i<N; i++)
        {
            if(pages[i]>threshold)
                return false;
            if(total+pages[i]<=threshold)
                total+=pages[i];
            else
            {
                student++;
                total = pages[i];
            }
            if(student>K)
                return false;
        }
        return true;
    }
    
    int findPages(vector<int> &pages, int K) {
        // code here
        int N = pages.size();
        if(N<K)
            return -1;
        long long low = 0;
        long long high = accumulate(pages.begin(), pages.end(), 0ll);
        
        if(K==1)
            return high;
        
        // cout<<low<<" "<<high<<endl;
        
        long long minPage;
        while(low<=high)
        {
            long long threshold = (low+high)/2;
            if(check(pages, N, K, threshold))
            {
                minPage = threshold;
                high = threshold-1;
            }
            else
                low = threshold+1;
            
        }
        return minPage;
    }
};
