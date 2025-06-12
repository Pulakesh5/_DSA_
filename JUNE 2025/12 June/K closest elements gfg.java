class Solution {
    int lowerBound(int[] arr, int x)
    {
        int low=0, high=arr.length-1, mid;
        while(low<high)
        {
            mid = low+(high-low)/2;
            if(arr[mid]<x)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
    int[] printKClosest(int[] arr, int k, int x) {
        // code here
        int index = lowerBound(arr, x);
        int N = arr.length;
        int left=index-1, right=index;
        if(index<N && arr[index]==x)
            right++;
        
        ArrayList<Integer> closest = new ArrayList<>();
        while(left>=0 && right<N && k!=0)
        {
            if(Math.abs(x-arr[left])>=Math.abs(x-arr[right]))
            {
                closest.add(arr[right++]);
            }
            else
                closest.add(arr[left--]);
            k--;
        }
        while(left>=0 && k!=0)
        {
            closest.add(arr[left--]);
            k--;
        }
        
        while(right<N && k!=0)
        {
            closest.add(arr[right++]);
            k--;
        }
        
        return closest.stream().mapToInt(Integer::intValue).toArray();
    }
}
