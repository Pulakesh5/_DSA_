class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> index = new ArrayList<>();
        for(int i=0; i<words.length; i++)
        {
            for(char ch:words[i].toCharArray())
            {
                if(ch==x)
                {
                    index.add(i);
                    break;
                }
            }
        }
        return index;
    }
}
