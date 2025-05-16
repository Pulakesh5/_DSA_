class Solution {
    public ArrayList<Integer> findSmallestRange(int[][] arr) {
        // code here
        int N = arr[0].length, k = arr.length;
        int[][] mergedList = new int[N*k][2];
        int mergedListSize=0; 
        for(int row=0; row<k; row++)
        {
            for(int num:arr[row])
                mergedList[mergedListSize++] = new int[]{row,num};
        }
        // sort the merged list
        Arrays.sort(mergedList, (a,b)->Integer.compare(a[1],b[1]));
        
        HashMap<Integer,Integer> freq = new HashMap<>(); // keeps track if elements from all rows are picked or not
        int[] range = new int[] {mergedList[0][1], mergedList[mergedListSize-1][1]}; // tracks answer
        int left = 0;
        for(int right=0; right<mergedListSize; right++)
        {
            freq.put(mergedList[right][0], freq.getOrDefault(mergedList[right][0],0)+1);
            
            while(freq.size()==k)
            {
                if(range[1]-range[0] > mergedList[right][1]-mergedList[left][1])
                {
                    range[0] = mergedList[left][1];
                    range[1] = mergedList[right][1];
                }
                
                if(freq.get(mergedList[left][0])==1)
                    freq.remove(mergedList[left][0]);
                else
                    freq.put(mergedList[left][0], freq.get(mergedList[left][0])-1);
                left++;
            }
        }
        ArrayList<Integer> rangeList = new ArrayList<>();
        rangeList.add(range[0]);
        rangeList.add(range[1]);
        return rangeList;
    }
}
