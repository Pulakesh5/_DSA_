class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxChunks = 0;
        int maxElement = -1;
        for(int i=0; i<arr.size(); i++)
        {
            maxElement = max(arr[i], maxElement);
            if(maxElement == i)
            {
                maxChunks++;
                maxElement = -1;
            }
        }
        return maxChunks;
    }
};
