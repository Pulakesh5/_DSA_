class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char smallestLetter = '$';
        int l = 0, r = letters.size() - 1, index;

        while(l<=r)
        {
            index = (l+r)/2;
            if(letters[index]<=target)
                l = index + 1;
            else
            {
                smallestLetter = (smallestLetter=='$'?letters[index] : min(smallestLetter, letters[index]));
                r = index - 1;
            }
        }
        return (smallestLetter == '$'? letters[0] : smallestLetter);
    }
};
