class Solution {
  public:
  double frac(pair<int,int> &p1, pair<int,int> &p2){
      double x1=p1.first,y1=p1.second;
      double x2=p2.first,y2=p2.second;
      return (y2-y1)/(x2-x1);
      
  }
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        int n=N,ans=INT_MIN;
        for(int i=0;i<n;i++){
            int curr=1;
            unordered_map<double,int> freq;
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j])
                {
                    curr++;
                    continue;
                }
                freq[frac(arr[i],arr[j])]++;
            }
            for(auto &e:freq){
                ans=max(ans,curr+e.second);
            }
        }
        return ans;
    }
};
