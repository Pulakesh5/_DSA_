class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        if(nums.size()==0)
            return {};
        int n=nums.size(), start, last = nums[0];
        string range = to_string(nums[0]);
        vector<string> ranges;
        for(int i=1; i<n; i++)
        {
            if(nums[i]==(last+1))
                last++;
            else
            {
                start = stoi(range);
                if(start<last)
                {
                    range+="->";
                    range+=to_string(last);
                }
                ranges.push_back(range);
                last = nums[i];
                range = to_string(nums[i]);
            }
        }
        start = stoi(range);
        if(start<last)
        {
            range+="->";
            range+=to_string(last);
        }
        ranges.push_back(range);

        return ranges; 
    }
};
