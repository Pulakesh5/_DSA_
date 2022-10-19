class Solution {
public:
    class comp{
        public:
                bool operator()(pair<int,string> &pr1, pair<int,string> &pr2)
                {
                    if(pr1.first!=pr2.first) return pr1.first<pr2.first;
                    return pr1.second>pr2.second;

                }          
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(string word:words)
            mp[word]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>, comp> pq;
        for(auto pr:mp)
            pq.push({pr.second,pr.first});
        vector<string> vs;
        for(int i=0;i<k;i++)
        {
            auto top = pq.top();
            cout<<top.first<<" "<<top.second<<endl;
            vs.push_back(top.second);
            pq.pop();
        }
        //sort(vs.begin(),vs.end());
        return vs;
    }
};
