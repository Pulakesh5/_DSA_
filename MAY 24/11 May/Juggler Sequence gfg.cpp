class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long> seq;
        seq.push_back(n);
        long long last;
        while(seq.back()!=1)
        {
            last = seq.back();
            if(last&1)
                seq.push_back(last*sqrt(last));
            else
                seq.push_back(sqrt(last));
        }
        return seq;
    }
};
