class Solution {
    public boolean isValid(String word) {
        boolean vowel = false, consonant = false, nonAlphaNumeric = false;
        for(char ch:word.toCharArray())
        {
            if(ch>='A' && ch<='Z')
                ch = (char)(ch-'A'+'a'); 

            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                vowel = true;
            else if(ch>='a' && ch<='z')
                consonant = true;
            else if(ch>='0' && ch<='9')
                continue;
            else
                nonAlphaNumeric = true;
        }
        return (word.length()>=3 && vowel && consonant && !nonAlphaNumeric);
    }
}
