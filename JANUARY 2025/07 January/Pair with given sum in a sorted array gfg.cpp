class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int left = 0, right = arr.size()-1, sum;
        int pairCount = 0;
        while(left < right)
        {
            sum = arr[left] + arr[right];
            if(sum < target)
                left++;
            else if(sum > target)
                right--;
            else
            {
                int ll=left+1, rr = right-1;
                while(ll<=right && arr[ll]==arr[left])
                    ll++;
                while(rr>=left && arr[rr]==arr[right])   
                    rr--;
                
                int leftCount = (ll-left), rightCount = (right-rr);
                if(target==2*arr[left])
                    pairCount += (leftCount*(leftCount-1))/2;
                else
                    pairCount += (leftCount*rightCount);
                    
                left = ll;
                right == rr;
            }
        }
        return pairCount;
    }
};
