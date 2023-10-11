class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;
        for(auto flower:flowers)
        {
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> answer;
        int started, finished;
        for(int person:people)
        {
            started  = upper_bound(start.begin(), start.end(), person) - start.begin();
            finished  = lower_bound(end.begin(), end.end(), person) - end.begin();
            answer.push_back(started - finished);
        }
        return answer;
    }
};
