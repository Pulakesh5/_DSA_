class Solution {
    public int maxDiff(int num) {
        String str = Integer.toString(num);
        char[] maxChars = str.toCharArray();
        char[] minChars = str.toCharArray();

        // Step 1: Find first non-9 digit for max replacement
        char replaceForMax = ' ';
        for (char c : maxChars) {
            if (c != '9') {
                replaceForMax = c;
                break;
            }
        }
        // Step 2: Replace that digit with 9 for max
        for (int i = 0; i < maxChars.length; i++) {
            if (maxChars[i] == replaceForMax) {
                maxChars[i] = '9';
            }
        }

        // Step 3: Replace first digit for min with 1 or second digit with 0 [if first digit is 1]
        char replaceForMin = '$';
        
        for(char ch:minChars)
        {
            if(ch>'1')
            {
                replaceForMin = ch;
                break;
            }
        }
        char replaceWith = (minChars[0]==replaceForMin) ? '1' : '0';
        for (int i = 0; i < minChars.length; i++) {
            if (minChars[i] == replaceForMin) {
                minChars[i] = replaceWith;
            }
        }
        // Step 4: Convert and calculate result
        int maxVal = Integer.parseInt(new String(maxChars));
        int minVal = Integer.parseInt(new String(minChars));

        return maxVal - minVal;
    }
}
        
