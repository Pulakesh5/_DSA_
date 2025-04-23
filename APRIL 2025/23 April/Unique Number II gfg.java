class Solution {

    public int countLargestGroup(int n) {
        HashMap<Integer,Integer> count = new HashMap<>();
        for(int num=1; num<=n; num++)
        {
            int tmp = num, digitSum = 0;
            while(tmp>0)
            {
                digitSum += (tmp%10);
                tmp /= 10;
            }
            count.putIfAbsent(digitSum,0);
            count.put(digitSum, count.get(digitSum)+1);
        }
        int largestGroup = 1, largestGroupSize=0;
        for(Map.Entry<Integer,Integer> entry:count.entrySet())
        {
            if(entry.getValue()>largestGroup)
            {
                largestGroup = entry.getValue();
                largestGroupSize = 1;
            }
            else if(entry.getValue()==largestGroup)
                largestGroupSize++;
        }
        return largestGroupSize;
    }
}
