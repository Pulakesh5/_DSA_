class Solution {
    class DigitCount {
        int digit;
        int count;
        public DigitCount(int digit, int count)
        {
            this.digit = digit;
            this.count = count;
        }
    }
    public String countAndSay(int n) {
        String str = "1";
        for(int i=0; i<(n-1); i++)
        {
            List<DigitCount> count = countDigits(str);
            str = makeString(count);
        }
        return str;
    }
    List<DigitCount> countDigits(String str)
    {
        List<DigitCount> count = new ArrayList<>();
        int N = str.length(), freq=0;
        char last = '$';
        for(int i=0; i<N; i++)
        {
            if(str.charAt(i)==last)
                freq++;
            else
            {
                if(last!='$')
                    count.add(new DigitCount((int)(last-'0'), freq));
                last = str.charAt(i);
                freq = 1;
            }
            // System.out.print(str.charAt(i)+" ");
        }
        count.add(new DigitCount((int)(last-'0'), freq));
        // System.out.println();
        return count;
    }
    String makeString(List<DigitCount> count)
    {
        String str = "";
        for(DigitCount dc:count)
        {
            str = str+Integer.toString(dc.count);
            str = str+Integer.toString(dc.digit);
            
        }
        return str;
    }
}
