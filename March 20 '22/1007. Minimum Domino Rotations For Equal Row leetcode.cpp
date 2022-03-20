class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        set<int> st;
        for(int i=1;i<=6;i++){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(tops[j]!=i && bottoms[j]!=i)
                {
                    flag=false;
                    break;
                }
            }
            if(flag) st.insert(i);
        }
        if(!st.size()) return -1;
        cerr<<st.size()<<"\\ \n";
        int ans1=INT_MAX,ans2=INT_MAX;
        for(auto it:st){
            cerr<<it<<" ";
            int change1=0,change2=0;
            for(int i=0;i<n;i++)
                if(tops[i]!=it) change1++;
            for(int i=0;i<n;i++)
                if(bottoms[i]!=it) change2++;
            ans1=min(change1,ans1);
            ans2=min(change2,ans2);
        }
        return min(ans1,ans2);
        
    }
};
