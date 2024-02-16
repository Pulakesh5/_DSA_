class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> frequency;
        for(int num:arr)
            frequency[num]++;
        vector<pair<int,int>> frequencyArr;
        for(auto freq:frequency)
            frequencyArr.push_back({freq.second, freq.first});
        sort(frequencyArr.begin(), frequencyArr.end());
        int leastUnique=frequency.size();
        for(int i=0; i<frequencyArr.size(); i++)
        {
            if(k<frequencyArr[i].first)
                return leastUnique;
            k-=frequencyArr[i].first;
            leastUnique--;
        }
        return 0;
    }
};
