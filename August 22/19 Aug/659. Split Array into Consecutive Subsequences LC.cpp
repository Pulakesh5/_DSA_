class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> notPicked;
        map<int,int> countSubseq;
        
        for(auto it:nums){
            notPicked[it]++;
        }
        
        for(auto num:nums){
            if(notPicked[num]==0) continue;
            
            notPicked[num]--;
            if(countSubseq[num-1]>0){
                countSubseq[num]++;
                countSubseq[num-1]--;
            }
            else if(notPicked[num+1]>0 && notPicked[num+2]>0){
                notPicked[num+1]--;
                notPicked[num+2]--;
                countSubseq[num+2]++;
            }
            else
                return false;
            
        }
        
        return true;
    }
};
