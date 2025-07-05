class Solution {
    public int findLucky(int[] arr) {
        // Method 1
        // Map<Integer,Integer> freq = new HashMap<>();
        // for(int num:arr)
        //     freq.put(num, freq.getOrDefault(num,0)+1);
        // int luckyNumber = -1;
        // for(Map.Entry<Integer, Integer> entry:freq.entrySet())
        // {
        //     if(entry.getKey()==entry.getValue())
        //     {
        //         luckyNumber = Math.max(luckyNumber, entry.getKey());
        //     }
        // }
        // return luckyNumber;
        
        // Method 2
        Arrays.sort(arr);
        int index=0, N=arr.length;
        int luckyNumber = -1;
        while(index<N)
        {
            int num = arr[index], count = 0;
            while(index<N && arr[index]==num)
            {
                count++;
                index++;
            }
            if(num==count)
                luckyNumber = num;
        }
        return luckyNumber;
    }
}
