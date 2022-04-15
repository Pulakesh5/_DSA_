class Solution {
  public:
    int Kadane(vector<int> &a){
        int n=a.size();
        
        int maxSum=INT_MIN,currSum=0,maxElement=INT_MIN;
        int end=-1;
        for(int i=0;i<n;i++){
            currSum+=a[i];
            if(currSum<0){
                currSum=0;
            }
            else if(currSum>maxSum){
                end=i;
                maxSum=currSum;
            }
            
        }
        if(end!=-1) return maxSum;
        return *max_element(a.begin(), a.end());
    }
    
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int maxSum=INT_MIN,currSum;
        
        vector<int> arr(R);
        
        for(int left=0; left<C ;left++){
            arr.assign(R,0);
            for(int right=left; right<C;right++){
                
                for(int i=0; i<R; i++){
                    arr[i]+=M[i][right];
                }
                currSum = Kadane(arr);
                if(currSum > maxSum)
                    maxSum=currSum;
            }
        }
        
        return maxSum;
    }
};
