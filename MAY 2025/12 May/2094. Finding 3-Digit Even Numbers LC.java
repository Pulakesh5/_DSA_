class Solution {
    public void backtrack(int[] digitCount, int number, int index, ArrayList<Integer> evenNumbers)
    {
        if(index==3)
        {
            evenNumbers.add(number);
            return;
        }
        if(index==0)
        {
            for(int digit=0; digit<9; digit+=2)
            {
                if(digitCount[digit]>0)
                {
                    digitCount[digit]--;
                    backtrack(digitCount, digit*(int)Math.pow(10,index)+number, index+1, evenNumbers);
                    digitCount[digit]++;
                }
            }
        }
        else
        {
            for(int digit=(index==2?1:0); digit<=9; digit++)
            {
                if(digitCount[digit]>0)
                {
                    digitCount[digit]--;
                    backtrack(digitCount, digit*(int)Math.pow(10,index)+number, index+1, evenNumbers);
                    digitCount[digit]++;
                }
            }
        }
    }
    public int[] findEvenNumbers(int[] digits) {
        boolean possible = false;
        int[] digitCount = new int[10];
        for(int digit:digits)
        {
            digitCount[digit]++;
            if(digit%2==0)
            {
                possible = true;
            }
        }
        if(!possible)
            return new int[]{};
        
        ArrayList<Integer> evenNumbers = new ArrayList<>();
        backtrack(digitCount, 0, 0, evenNumbers);
        Collections.sort(evenNumbers);
        return evenNumbers.stream().mapToInt(i -> i).toArray();
    }
}
