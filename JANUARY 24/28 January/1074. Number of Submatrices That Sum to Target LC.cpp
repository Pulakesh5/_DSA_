class Solution {
public:
    // first try this : https://leetcode.com/problems/subarray-sum-equals-k/
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        
        vector<vector<int>> sum(row+1,vector<int>(col+1));
        
        for(int i=0;i<row;i++){
            for(int j=1;j<col;j++){
                matrix[i][j]+= matrix[i][j-1];
            }
        }
        int ans=0,curr=0;
        unordered_map<int,int> count;
        for(int i=0;i<col;i++){
            for(int j=i;j<col;j++){
                count={{0,1}};
                curr=0;
                for(int k=0;k<row;k++){
                    curr+= matrix[k][j] -(i>0 ? matrix[k][i-1] : 0);
                    ans += (count.find(curr-target)!=count.end() ? count[curr-target] : 0);
                    count[curr]++;
                }
            }
        }
        return ans;
    }
};
