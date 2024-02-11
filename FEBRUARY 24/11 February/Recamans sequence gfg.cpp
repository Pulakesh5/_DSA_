class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        set<int> seq;
        vector<int> recSeq={0};
        seq.insert(0);
        int last=0;
        for(int i=1; i<=n; i++)
        {
            if(last-i>0 && seq.find(last-i)==seq.end())
            {
                last = last-i;
                
            }
            else
                last = last + i;  
            seq.insert(last);
            recSeq.push_back(last);
        }
        return recSeq;
    }
};
