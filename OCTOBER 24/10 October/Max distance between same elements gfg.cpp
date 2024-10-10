class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int, int> firstPos;
        int N = arr.size(), maxDistance = 1;
        for(int i=0; i<N; i++) {
            if(firstPos.find(arr[i])==firstPos.end())
                firstPos[arr[i]] = i;
            else
                maxDistance = max(maxDistance, i-firstPos[arr[i]]);
        }
        return maxDistance;
    }
};
