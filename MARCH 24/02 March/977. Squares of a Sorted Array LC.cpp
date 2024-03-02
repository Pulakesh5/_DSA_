class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> squares(len);
        int neg, pos, k=0;
        pos = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        neg = pos-1;
        
        long long negSq, posSq;
        
        while(neg>=0 && pos<len)
        {
            negSq = 1ll*nums[neg];
            negSq*=nums[neg];
            posSq = 1ll*nums[pos];
            posSq*=nums[pos];

            if(negSq<posSq)
            {
                squares[k++] = negSq;
                neg--;
            }
            else
            {
                squares[k++] = posSq;
                pos++;
            }
        }


        while(neg>=0)
        {
            negSq = 1ll*nums[neg];
            negSq*=nums[neg];
            squares[k++] = negSq;
            neg--;
        }
        while(pos<len)
        {
            posSq = 1ll*nums[pos];
            posSq*=nums[pos];
            squares[k++] = posSq;
            pos++;
        }

        return squares;
    }
};
