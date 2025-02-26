class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        vector<int> ans(arr.size());
        vector<int> nse(arr.size(),arr.size()),pse(arr.size(),0);
        stack<int> sh;
        for(int i=0;i<arr.size();i++){
            while(!sh.empty() && arr[sh.top()] >= arr[i]){
                int ele = sh.top();
                nse[ele] = i;
                sh.pop();
                pse[ele] = (sh.empty()) ? -1 : sh.top();
            }
            sh.push(i);
        }
        
        while(!sh.empty()){
            int ele = sh.top();
            nse[ele] = arr.size();
            sh.pop();
            pse[ele] = (sh.empty()) ? -1 : sh.top();
        }
        for(int i=0;i<arr.size();i++){
            int ws = nse[i] - pse[i] - 1;
            ans[ws-1] = max(ans[ws-1],arr[i]);
        }
        for(int i=arr.size()-2;i>=0;i--){
            ans[i] = max(ans[i+1],ans[i]);
        }
        
        return ans;
    }
    
};
