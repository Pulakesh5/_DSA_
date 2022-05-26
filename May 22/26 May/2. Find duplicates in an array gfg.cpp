class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        int count[n]={0};
        for(int i=0;i<n;i++){
            count[arr[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(count[i]>1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};
