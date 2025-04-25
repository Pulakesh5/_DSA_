class Solution {
    static int majorityElement(int arr[]) {
        // code here
        int majority_element = arr[0], majorityCount = 1;
        int N = arr.length;
        for(int i=1; i<N; i++)
        {
            if(majority_element == arr[i])
                majorityCount++;
            else
            {
                majorityCount--;
                if(majorityCount==0)
                {
                    majority_element = arr[i];
                    majorityCount = 1;
                }
            }
            // System.out.println(majority_element+" "+majorityCount);
        }
        int count=0;
        for(int num:arr)
            count = count+(num==majority_element?1:0);
        if(count>=(N/2)+1)
            return majority_element;
        return -1;
    }
}
