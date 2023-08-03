class Solution {
public:
    vector<vector<char>> mapping;
    vector<string> combinations;
    void backtrack(string &digits, int index, string &combination)
    {
        if(index>=digits.size())
        {
            if(combination.size())
                combinations.push_back(combination);
            return;
        }
            
        int digit = digits[index] - '0';
        for(int i=0; i<mapping[digit].size(); i++)
        {
            combination.push_back(mapping[digit][i]);
            backtrack(digits, index+1, combination);
            combination.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        mapping.resize(11);
        mapping[2] = {'a','b','c'};
        mapping[3] = {'d','e','f'};
        mapping[4] = {'g','h','i'};
        mapping[5] = {'j','k','l'};
        mapping[6] = {'m','n','o'};
        mapping[7] = {'p','q','r','s'};
        mapping[8] = {'t','u','v'};
        mapping[9] = {'w','x','y','z'};
        string combination;
        backtrack(digits, 0, combination);
        return combinations;
    }
};
