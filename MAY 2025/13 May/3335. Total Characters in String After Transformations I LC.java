class Solution {
    public int lengthAfterTransformations(String s, int t) {
        int[] charFreq = new int[26];
        for(char ch:s.toCharArray())
            charFreq[(int)(ch-'a')]++;
        int mod = (int)(1e9+7);
        for(int itr=0; itr<t; itr++)
        {
            int zCount = charFreq[25];
            for(int i=25; i>0; i--)
            {
                charFreq[i] = charFreq[i-1];
            }
            charFreq[0] = zCount;
            charFreq[1] = (charFreq[1]+zCount)%mod;
        }
        int length = 0;
        for(int i=0; i<26; i++)
            length = (length+charFreq[i])%mod;
        return length;
    }
}
