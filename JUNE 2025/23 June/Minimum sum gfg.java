class Solution {
    String minSum(int[] arr) {
        // code here
        Arrays.sort(arr);
        StringBuilder sb = new StringBuilder();
        int carry = 0, i;
        for(i=arr.length-1; i>0; i-=2)
        {
            carry += (arr[i]+arr[i-1]);
            if(carry!=0)
                sb.append((char)('0'+carry%10));
            carry /= 10;
        }
        if(i>=0 && (carry+arr[0])>0)
        {
            carry += arr[0];
            sb.append((char)('0'+carry%10));
            carry /= 10;
        }
        if(carry>0)
        {
            sb.append((char)('0'+carry));
        }
        return sb.reverse().toString();
    }
}
