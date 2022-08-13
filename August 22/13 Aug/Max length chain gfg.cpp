class Solution{
public:
    /*You are required to complete this method*/
    static bool comp(val &a, val &b){
        return a.second < b.second;
    }
    
    int maxChainLen(struct val arr[],int n){
        
        sort(arr , arr+n , comp);
        if(n==0) return 0;
        
        int end=arr[0].second, maxLength=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i].first>end){
                end=arr[i].second;
                maxLength++;
            }
        }
        return maxLength;
    }
};
