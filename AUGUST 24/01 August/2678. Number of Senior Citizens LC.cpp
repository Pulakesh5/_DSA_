class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0, age;
        for(string detail:details)
        {
            age = stoi(detail.substr(11,2));
            if(age>60)
                seniorCount++;
        }
        return seniorCount;
    }
};
