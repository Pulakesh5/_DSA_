class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(), arr.end());
        vector<int> uniques;
        for(int num:arr)
        {
            if(uniques.empty() || uniques.back()!=num)
                uniques.push_back(num);
        }
        
        size_t N = uniques.size();
        int consecutiveSequenceLast = uniques[0], maxSeqLen = 1, seqLen = 1;
        for(int i=1; i<N; i++)
        {
            if(uniques[i] == (consecutiveSequenceLast+1))
            {
                consecutiveSequenceLast++;
                seqLen++;
                if(seqLen>maxSeqLen)
                    maxSeqLen = seqLen;
            }
            else
            {
                consecutiveSequenceLast = uniques[i];
                seqLen = 1;
            }
        }
        if(seqLen > maxSeqLen)
            return seqLen;
        return maxSeqLen;
    }
};
