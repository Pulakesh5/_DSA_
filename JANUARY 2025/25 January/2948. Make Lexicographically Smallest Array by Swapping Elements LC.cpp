class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& OriginalNums, int limit) {

        vector<int> nums = OriginalNums;
        sort(nums.begin(), nums.end());
        int N = nums.size();

        unordered_map<int, vector<int>> groupToList;
        unordered_map<int, int> numToGroup;

        int groupNumber = 0;
        groupToList[groupNumber].push_back(nums[N-1]);
        numToGroup[nums[N-1]] = groupNumber;
        for(int i=N-2; i>=0; i--)
        {
            if(nums[i+1]-nums[i] > limit)
                groupNumber++;
            groupToList[groupNumber].push_back(nums[i]);
            numToGroup[nums[i]] = groupNumber;
        }

        vector<int> answer(N);
        for(int i=0; i<N; i++)
        {
            groupNumber = numToGroup[OriginalNums[i]];
            // cout<<OriginalNums[i]<<", group = "<<groupNumber<<", last = "<<groupToList[groupNumber].back()<<endl;
            answer[i] = groupToList[groupNumber].back();
            groupToList[groupNumber].pop_back();
        }

        return answer;
    }
};
