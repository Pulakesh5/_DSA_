class Solution {
  public:
    int countDifference(string word1, string word2)
    {
        int diff = 0, len = word1.size();
        for(int i=0; i<len; i++)
        {
            diff += abs(word1[i]-word2[i]);
        }
        return diff;
    }
    int minimum_difference(int n, vector<string> &words) {
        // Code here.
        int minDiff = INT_MAX;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                minDiff = min(minDiff, countDifference(words[i], words[j]));
            }
        }
        return minDiff;
    }
};
