class Solution {
public:
    string frequencySort(string s) {
        vector<int> countChar(256,0);
        for(char ch:s)
        {
            countChar[(int)ch]++;
        }
        vector<pair<int,char>> vp;
        for(int i=0; i<256; i++)
        {
            if(countChar[i]==0)
                continue;
        
            vp.push_back({countChar[i],(char)i});
        }
        sort(vp.begin(),vp.end());
        string sorted="";
        for(auto it=vp.rbegin(); it!=vp.rend(); it++)
        {
            string str((*it).first, (*it).second);
            sorted+=str;
        }
        return sorted;
    }
};
