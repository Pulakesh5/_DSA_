class Solution {
    public int minAddToMakeValid(String s) {
        int minAdd = 0, balance = 0;
        for(char ch:s.toCharArray()) {
            if(ch=='(')
                balance++;
            else
            {
                balance--;
                if(balance<0)
                {
                    minAdd++;
                    balance = 0;
                }
            }
        }
        minAdd += balance;
        return minAdd;
    }
}
