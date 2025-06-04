class Solution {
    public String answerString(String word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.length(), m = n - numFriends + 1;
        String res = "", cur = "";
        for (int i = 0; i < n; ++i) {
            cur = word.substring(i, Math.min(i + m, n));
            if (res.compareTo(cur) < 0) {
                res = cur;
            }
        }
        return res;
    }
}
