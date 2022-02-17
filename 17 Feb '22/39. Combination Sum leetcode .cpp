//Classic Backtracking question
class Solution {
public:
    vector<int> item;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        item=candidates;
        sort(item.begin(), item.end());
        backtrack(temp, 0, target);
        return res;
    }
private:
    void backtrack(vector<int> temp,int start, int target){
        if(target==0)
        {
            res.push_back(temp);
            return ;
        }
        else{
            for(int i=start;i<item.size() && item[i]<=target;i++){
                temp.push_back(item[i]);
                backtrack(temp, i, target-item[i]); // start wont be start+1 because we can use same candidate, otherwise it would've been
                temp.pop_back();
            }
        }
        
    }
};
