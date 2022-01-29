// Monotonic Stack ka problem hai like next greater element
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> index;
        int n=heights.size(),ans=0;
        for(int i=0;i<n;i++){
            while(!index.empty() && heights[index.top()]>=heights[i]){
                int h = heights[index.top()]; index.pop();
                int l = index.size() > 0 ? index.top() : -1;
                ans = max(ans, h*(i-l-1)); 
            }
            index.push(i);
        }
        return ans;
        
        
    }
};
