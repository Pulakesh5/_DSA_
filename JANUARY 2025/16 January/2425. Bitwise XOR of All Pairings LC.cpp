class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2=nums2.size();
        if(n1%2 == 0 && n2%2==0)
            return 0;
        vector<long long> bitFreq1(32), bitFreq2(32);
        for(int num:nums1)
        {
            int pos=0;
            while(num)
            {
                bitFreq1[pos++]+=(num&1);
                num = num>>1;
            }
        }
        for(int num:nums2)
        {
            int pos=0;
            while(num)
            {
                bitFreq2[pos++]+=(num&1);
                num = num>>1;
            }
        }
        
        // for(int i=0; i<4; i++)
        //     cout<<i<<"  "<<bitFreq1[i]<<" "<<bitFreq2[i]<<endl;
        
        
        int finalXOR = 0;
        for(int i=0; i<31; i++)
        {
            if((bitFreq1[i]*n2)%2 != (bitFreq2[i]*n1)%2)
                finalXOR = finalXOR | (1<<i);
        }
        return finalXOR;
        // nums1 = 
        // 001 
        // 010
        // nums2 = 
        // 011 
        // 100
        // nums3 = 
        // 010 
        // 001 
        // 101 
        // 110
    }
};
