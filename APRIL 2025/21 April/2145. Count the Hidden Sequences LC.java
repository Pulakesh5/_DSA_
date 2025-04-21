class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        long minLow = 0, maxHigh = 0;
        long sum = 0L;
        for(int diff:differences)
        {
            sum += diff;
            if(sum<minLow)
                minLow = sum;
            if(sum>maxHigh)
                maxHigh = sum;
        }
        if(upper-lower<maxHigh-minLow)
            return 0;
        return (int)((upper-lower)-(maxHigh-minLow)+1);

    }
}
