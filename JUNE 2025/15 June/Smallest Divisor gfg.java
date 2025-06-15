class Solution {
    int smallestDivisor(int[] arr, int k) {
        // Code here
        int low = 1, high = (int)1e6;
        int divisor;
        while(low<high)
        {
            divisor = (low+high)/2;
            int count = 0;
            for(int num:arr)
                count += (num+divisor-1)/divisor;
            
            if(count>k)
                low = divisor+1;
            else
                high = divisor;
        }
        return low;
    }
}
