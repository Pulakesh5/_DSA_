class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int N = arr.length;
        if(N<3)
            return false;
        for(int i=2; i<N; i++)
        {
            if(arr[i]%2==1 && arr[i-1]%2==1 && arr[i-2]%2==1)
                return true;
        }
        return false;
    }
}
