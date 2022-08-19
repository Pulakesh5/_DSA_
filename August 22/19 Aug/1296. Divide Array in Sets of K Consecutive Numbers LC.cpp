class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> count;
        for(int num:nums)
            count[num]++;
        sort(nums.begin(), nums.end());
        for(auto &num:nums)
        {
            if(count[num]==0) continue;
            
            for(int _nm=num;_nm<(num+k);_nm++)
            {
                if(count[_nm]==0)
                {
                  
                    return false;
                }
                count[_nm]--;
            }
                            
        }
        return true;
    }
};
