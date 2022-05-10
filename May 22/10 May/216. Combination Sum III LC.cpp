class Solution {
public:
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=1;i<=512;i++){
            bitset<10> bit(i);
            if(bit.count()!=k) continue;
            else{
                //cout<<"called "<<i<<" set "<<'\n';
                int curr_sum=0;
                for(int j=0;j<=9;j++){
                    if(bit[j]){
                        //cout<<j<<" ";
                        curr_sum+=(j+1);
                        temp.push_back(j+1);
                    } 
                }
                //cout<<'\n';
                if(curr_sum==n){
                    ans.push_back(temp);
                }
                temp.clear();
            }
        }
        return ans;
    }
};
