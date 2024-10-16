class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a)
            pq.push({a, 'a'});
        if(b)
            pq.push({b, 'b'});
        if(c)
            pq.push({c, 'c'});
        string diverseString = "";
        while(pq.size()>1) {
            pair<int, char> top1 = pq.top(); pq.pop();
            pair<int, char> top2 = pq.top(); pq.pop();

            if(top1.first>=2){
                diverseString.push_back(top1.second);
                diverseString.push_back(top1.second);
                top1.first-=2;
            } else {
                diverseString.push_back(top1.second);
                top1.first-=1;
            }

            if(top2.first>=2 && top2.first>=top1.first){
                diverseString.push_back(top2.second);
                diverseString.push_back(top2.second);
                top2.first-=2;
            } else {
                diverseString.push_back(top2.second);
                top2.first-=1;
            }


            if(top1.first)
                pq.push(top1);
            if(top2.first)
                pq.push(top2);
        }
        if(pq.empty())
            return diverseString;
        if(pq.top().first>=2)
        {
            diverseString.push_back(pq.top().second);
            diverseString.push_back(pq.top().second);
        }
        else
            diverseString.push_back(pq.top().second);
        return diverseString;
    }
};
