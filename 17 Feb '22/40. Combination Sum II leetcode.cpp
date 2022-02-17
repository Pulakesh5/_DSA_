class Solution {
public:
    vector<int> item;
    set<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        item=candidates;
        sort(item.begin(), item.end());
        backtrack(temp, 0, target);
        vector<vector<int>> ans;
        for(auto it:res)
            ans.push_back(it);
        return ans;
    }
private:
    void backtrack(vector<int> temp,int start, int target){
        if(target==0)
        {
            res.insert(temp);
            return ;
        }
        else{
            for(int i=start;i<item.size() && item[i]<=target;i++){
                if(i>start && item[i]==item[i-1]) continue;
                temp.push_back(item[i]);
                backtrack(temp, i+1, target-item[i]); // start wont be start+1 because we can use same candidate, otherwise it would've been
                temp.pop_back();
            }
        }
        
    }
};
