    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();
        vector<int> modCount(k+1,0);
        for(int i=0;i<n;i++)
        {
            modCount[nums[i]%k]++;
        }
        
        if(modCount[0]%2) return false;
        
        for(int i=1;i<((k+1)/2);i++)
        {
            if(modCount[i]!=modCount[k-i])
                return false;
        }
        
        if(!(k%2) && (modCount[k/2]%2)) return false;
        
        return true;
    }
