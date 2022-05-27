class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
      
        int first,second;
      
        double n_d=((n*1.0)/(d*1.0));
      
        double mx=-1;
       
        int ans1=n,ans2=10000*(d/n)+1;
        
        for(int i=n+1;i<=10000;i++){
            first=i;
            second=(i*d)/n + 1;
            if(second>10000) break;
            double frac=(first*1.0)/(second*1.0);
            if(frac<n_d && frac>mx){
                mx=frac;
                ans1=first;
                ans2=second;
            }
        }
        return {ans1,ans2};
    }
};
