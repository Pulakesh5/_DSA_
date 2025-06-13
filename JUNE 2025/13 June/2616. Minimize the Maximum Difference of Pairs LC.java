class Solution {
    int check(int[] arr, int s)
    {
        int count = 0;
        for(int pile:arr)
        {
            count += (pile+s-1)/s;
        }
        return count;
    }
    public int kokoEat(int[] arr, int k) {
        // code here
        long low = 1, high = Arrays.stream(arr).max().getAsInt()+1;
        long minS, count;
        while(low<high)
        {
            minS = low+(high-low)/2;
            count = check(arr, (int) minS);
            if(count>k)
                low = minS+1;
            else
                high = minS;
            // System.out.println(minS+" "+count);
        }
        return (int)low;
    }
}
