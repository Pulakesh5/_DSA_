#define ppi pair<int, int> 
class Solution {
  public:
    
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        if(N==1)
            return {A[0]+B[0]};
            
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        priority_queue<ppi> pq;
        
        vector<int> V;
        
        // pq.push({A[N-1]+B[N-1],{N-1,N-1}});
        for(int i=0; i<N; i++)
            pq.push({A[i]+B[N-1], N-1});
        while(!pq.empty() && K--)
        {
            ppi top = pq.top();
            pq.pop();
            
            int sum = top.first;
            int i = top.second;
            V.push_back(sum);
            if(i-1>=0)
                pq.push({sum-B[i]+B[i-1], i-1});
            
            // cout<<i<<" "<<j<<endl;
            // if(i>0)
            //     pq.push({A[i-1]+B[j], {i-1,j}});
            // if(j>0)
            //     pq.push({A[i]+B[j-1], {i,j-1}});
            
        }
        
        return V;
    
    }
};
