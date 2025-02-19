class Solution {
public:
    bool backtrack(string &happyString, int n, int &k) {
    // Base Case: Stop when the desired length is reached
    if (happyString.length() == n) {
        // If this is the kth happy string, return true
        if (--k == 0) {
            return true;
        }
        return false;
    }

    // Try adding each character
    for (int i = 0; i < 3; i++) {
        if (happyString.empty() || happyString.back() != ('a' + i)) {
            happyString.push_back('a' + i);
            if (backtrack(happyString, n, k)) {
                return true;
            }
            happyString.pop_back(); // Backtrack step
        }
    }

    return false;
}

    string getHappyString(int n, int k) {
        string happyString = "";
        backtrack(happyString, n, k);
        return happyString;
    }
};
