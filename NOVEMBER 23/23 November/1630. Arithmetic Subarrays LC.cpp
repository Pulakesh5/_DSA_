class Solution {
public:
    // vector<int> arr;
    bool checkArithmetic(vector<int> arr, int l, int r)
    {
        if(r-l==1)
            return true;
        sort(arr.begin()+l, arr.begin()+r+1);
        for(int i=l+2; i<=r; i++)
        {
            cout<<arr[i-1]<<" "<<arr[i]<<endl;
            if(arr[i]-arr[i-1]!=arr[i-1]-arr[i-2])
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int len = nums.size(), m=l.size();
        // arr.resize(len);
        // for(int i=0; i<len; i++) arr[i]=nums[i];
        vector<bool> answer(m,true);
        for(int i=0; i<m; i++)
        {
            if(!checkArithmetic(nums, l[i], r[i]))
                answer[i] = false;
            cout<<endl;
        }
        return answer;
    }
};
