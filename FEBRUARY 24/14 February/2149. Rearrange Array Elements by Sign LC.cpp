class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives, negatives;
        for(int num:nums)
        {
            if(num>0)
                positives.push_back(num);
            else
                negatives.push_back(num);
        }
        int n = nums.size();
        vector<int> arr(n);
        for(int i=0; i<n; i+=2)
            arr[i] = positives[i/2];
        for(int i=1; i<n; i+=2)
            arr[i] = negatives[i/2];

        return arr;
    }

};
