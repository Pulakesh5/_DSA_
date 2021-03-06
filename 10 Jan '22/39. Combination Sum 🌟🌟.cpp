// Problem Link: https://leetcode.com/problems/combination-sum/
//Tags: Backtracking , Subset Sum
/* Important Leetcode
discussion links : https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c%2B%2B-solution-use-backtracking-easy-understand.
                   https://leetcode.com/problems/combination-sum/discuss/16502/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)
 */                                  
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> item;
    int n;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        item=candidates;
        n=item.size();
        sort(item.begin(),item.end());
        vector<int> temp_list;
        combination_sum(temp_list, target, 0);
        
        //vector<vector<int>> rtn(ans.begin(),ans.end());
        return ans;
    }
private:
    void combination_sum(vector<int> &temp_list, int target, int start)
    {
        if(target==0)
        {
            ans.push_back(temp_list);
            return;
        }
        for(int i=start;i<n && target>=item[i];i++)
        {
            temp_list.push_back(item[i]);
            combination_sum(temp_list, target-item[i], i);
            temp_list.pop_back();
        }
    }
};
