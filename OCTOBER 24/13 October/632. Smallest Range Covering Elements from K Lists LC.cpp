class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> list;
        for(int i=0; i<nums.size(); i++) {
            for(int num:nums[i])
                list.push_back({num, i});
        }
        sort(list.begin(), list.end());

        int l=0, k=0;
        unordered_map<int, int> count;
        vector<int> range;
        int N = list.size();

        for(size_t r=0; r<N; r++) { // moving the right end
        
            if(!count[list[r].second]++) {
                k++;
            }

            if(k == nums.size()) {
                while(count[list[l].second] > 1)
                    --count[list[l++].second]; // moving the left end
                if(range.size() == 0 || range[1]-range[0] > list[r].first - list[l].first)
                    range = {list[l].first, list[r].first};
            }
        }
        return range;
    }
};
