class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int n=horizontalCuts.size();
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        long long maxHor=max(horizontalCuts[0],h-horizontalCuts[n-1]);
        for(int i=1;i<n;i++){
            maxHor=max(maxHor,1ll*(horizontalCuts[i]-horizontalCuts[i-1]));
        }
        
        n=verticalCuts.size();
        long long maxVer=max(verticalCuts[0], w-verticalCuts[n-1]);
        for(int i=1;i<n;i++){
            maxVer=max(maxVer,1ll*(verticalCuts[i]-verticalCuts[i-1]));
        }
        
        return (maxVer*maxHor)%(1000000007ll);
    }
};
