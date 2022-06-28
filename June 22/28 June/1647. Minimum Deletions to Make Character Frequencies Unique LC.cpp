class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26,0);
        map<int,int> mp;
        priority_queue<int> pq;
        int n=s.size();
        for(int i=0;i<n;i++)
            count[s[i]-'a']++;
        for(int i=0;i<26;i++){
            if(count[i]>0)
            {
                mp[count[i]]++;
                pq.push(count[i]);
            }
        }
        int ans=0;
        while(pq.size()>1){
            int tp1=pq.top();
            pq.pop();
            int tp2=pq.top();
            if(tp1==tp2){
                while(tp1>0 && mp.find(tp1)!=mp.end()){
                    ans++;tp1--;
                }
                mp[tp2]--;
                mp[tp1]++;
                if(tp1>0)
                    pq.push(tp1);
            }
        }
        
        return ans;
    }
};

///////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26,0);
        for(char ch:s){
            count[ch-'a']++;
        }
        int ans=0;
        sort(count.begin(), count.end());
        
        for(int i=24;i>=0 && count[i]>0;--i){
            ans += max(0, count[i] - max(0,count[i+1]-1));
            count[i] = min(count[i],max(0,count[i+1]-1));
        }
        return ans;
    }
};
