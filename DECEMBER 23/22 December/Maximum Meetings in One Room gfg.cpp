class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<pair<int, int>, int>> temp;
        
        for(int i=0; i<N; i++){
            temp.push_back({{F[i], S[i]}, i+1});
        }
        
        sort(temp.begin(), temp.end());
        
        vector<int> ans;
        ans.push_back(temp[0].second);
        int finalTime = temp[0].first.first;
        
        for(int i=1; i<N; i++){
            if(temp[i].first.second > finalTime){
                ans.push_back(temp[i].second);
                finalTime = temp[i].first.first;
            }
        }
        
        sort(ans.begin(), ans.end() );
        return ans;
    }
};
