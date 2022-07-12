class Solution {
public:
    long long target;
    bool makesquare(vector<int>& a) {
        
        long long sum=0;
        for(int i=0;i<a.size();i++) 
            sum+=a[i];
        
        if(sum%4!=0) return false;
        
        target=sum/4;
        sort(a.begin(),a.end(), greater<int> ());
        vector<long long> sums(4,target);
        bool ans=backtrack(a,sums,0);
        
        return ans; 
    }
    bool backtrack(vector<int> &a, vector<long long> &sums, int index){
        if(index==a.size())
            return true;
        
        unordered_set<int> s; // to not try making some sums meet target

        for(int i=0;i<4;i++){
            
            if(sums[i]>=a[index] && !s.count(sums[i])){
                sums[i]-=a[index];
                if(backtrack(a,sums,index+1))
                    return true;
                sums[i]+=a[index];
                s.insert(sums[i]);
            }
        }
        return false;
    }
};
