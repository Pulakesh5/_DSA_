    int removeStudents(int H[], int N) {
        // code here
        if(N==0) return 0;
        
        vector<int> end;
        //return LongestIncreasingSubsequenceLength(end);
        end.push_back(H[0]);
        
        for(int i=1;i<N;i++)
        {
            if(end.back()<H[i])
                end.push_back(H[i]);
            else
                end[lower_bound(end.begin(),end.end(),H[i])-end.begin()]=H[i];
        }
        return N-end.size();
    }
