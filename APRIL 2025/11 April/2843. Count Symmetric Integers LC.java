class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int num=low; num<=high; num++)
        {
            if(num>=10 && num<=99)
            {
                if(num/10 == num%10)
                {
                    count++;
                }
            }
            else if(num>=1000 && num<=9999)
            {
                if(num/1000+(num/100-10*(num/1000)) == (num/10-10*(num/100)+num%10))
                {
                    count++;
                }
            }
        }
        return count;
    }
}
