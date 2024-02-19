class Solution{
public:
    int minValue(string s, int k){
        // code here
        priority_queue<int> pq;
        vector<int> charFreq(26);
        for(char ch:s)
            charFreq[ch-'a']++;
        for(int i=0; i<26; i++)
        {
            if(charFreq[i])
                pq.push(charFreq[i]);
        }
        while(k--)
        {
            int top = pq.top();
            pq.pop();
            if(top-1)
                pq.push(top-1);
        }
        int value=0;
        while(pq.size())
        {
            value+=pow(pq.top(),2);
            pq.pop();
        }
        return value;
    }
};
