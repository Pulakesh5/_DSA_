static const int fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    return 0;
}();
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int oneCount = 0, N = nums.size();
        for(int num:nums)
        {
                oneCount+=num;
        }
        if(oneCount==N)
            return 0;
        int minMoves = oneCount;
        int count = 0, l=0, r=0;
        while(l<N)
        {
            while(r>=l ? (r-l<oneCount) : ((N-l+r) < oneCount))
            {
                count += nums[r];
                r = (r+1)%N;
            }
            minMoves = min(minMoves, oneCount-count);
            count-=nums[l++];
        }
        return minMoves;
    }
};
