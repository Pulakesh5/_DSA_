class Solution {
    public int possibleStringCount(String word) {
        char last = '$';
        int lastCount = 1;
        int stringCount = 0;
        for(char ch:word.toCharArray())
        {
            if(ch==last)
                lastCount++;
            else
            {
                stringCount += (lastCount-1);
                last = ch;
                lastCount = 1;
            }
        }
        stringCount += (lastCount-1);
        return stringCount+1; // extra 1 if the original string was the intended one
    }
}
