class Solution {
    public static int lowerBound(int arr[], int val)
    {
        int left = 0, right = arr.length-1, mid;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(arr[mid]<=val)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    public static ArrayList<Integer> countLessEq(int a[], int b[]) {
        // code here
        Arrays.sort(b);
        int N1 = a.length, N2 = b.length;
        ArrayList<Integer> countLessThanOrEqual = new ArrayList<>();
        for(int i=0; i<N1; i++)
        {
            int count = lowerBound(b, a[i]);
            countLessThanOrEqual.add(count);
        }
        return countLessThanOrEqual;
    }
}
