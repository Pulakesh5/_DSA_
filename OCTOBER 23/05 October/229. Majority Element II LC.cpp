class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0, cnt2=0;
        int major1=-1, major2=-1;
        for(int num:nums)
        {
            if(num==major1)
                cnt1++;
            else if(num == major2)
                cnt2++;
            else if(cnt1==0)
            {
                cnt1=1;
                major1=num;
            }
            else if(cnt2 == 0)
            {
                cnt2=1;
                major2=num;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int num:nums)
        {
            if(num==major1)
                cnt1++;
            else if(num==major2)
                cnt2++;
        }
        vector<int> majors;
        if(cnt1>(nums.size()/3))
            majors.push_back(major1);
        if(cnt2>(nums.size()/3))
            majors.push_back(major2);

        return majors; 
    }
};
