class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        set<int> distinct;
        for(int i=0;i<n;i++){
            distinct.insert(arr[i]);
        }
        int distinct_count=distinct.size();
        int count=0,i=0;
        int start=0,end=i,ans=0;
        unordered_map<int,int> mp;
        
        for(i=0;i<n;i++){
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=1;
                count++;
            }
            else
                mp[arr[i]]++;
            
            end++;
            if(count==distinct_count) break;
        }
        
        while(count==distinct_count){
            
            while(start<n && count==distinct_count){
                ans+=(n-end+1);
                mp[arr[start]]--;
                if(mp[arr[start]]==0){
                    count--;
                    mp.erase(arr[start]);
                }
                start++;
            }
            
            while(end<n && count!=distinct_count){
                if(mp.find(arr[end])==mp.end()){
                    mp[arr[end]]=1;
                    count++;
                }
                else
                    mp[arr[end]]++;
                
                end++;
            }
        }
        
        return ans;
    }
};
