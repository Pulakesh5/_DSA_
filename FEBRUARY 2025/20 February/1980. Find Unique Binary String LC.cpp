class Solution {
public:
    void str_to_dec(vector<string> &nums, vector<int> &vals)
    {
        int len = nums[0].size();
        for(string s:nums)
        {
            int num = 0;
            for(int i=0; i<len; i++)
            {
                num = num*2 + (s[i]-'0');
            }
            vals.push_back(num);
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int N = nums.size();
        vector<int> num_val;
        str_to_dec(nums, num_val);
        sort(num_val.begin(), num_val.end());
        int ans = N;
        for(int i=0; i<N; i++)
        {
            if(num_val[i] != i)
            {
                ans = i;
                break;
            }
        }
        int i=0, len = nums[0].size(); 
        string ans_str = "";
        while(i++<len)
        {
            if(ans%2)
                ans_str = "1" + ans_str;
            else
                ans_str = "0" + ans_str;
            ans /= 2;
        }
        return ans_str;
    }
};
