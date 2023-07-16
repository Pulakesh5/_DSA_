class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int countOfPeople = people.size(), countOfReqSkills = req_skills.size();
        //Hashing the skill name with their index
        map<string,int> skillId;
        for(int i=0; i<req_skills.size(); i++)
            skillId[req_skills[i]] = i;
        //Creating skillMask for each person
        vector<int> skillMaskPeople(countOfPeople);
        int skillMask;
        for(int i=0; i<countOfPeople; i++)
        {
            skillMask = 0;
            for(string skill:people[i])
            {
                skillMask = skillMask | (1<<skillId[skill]);
            }
            skillMaskPeople[i] = skillMask;
        }
        int smallerTeamMask, m = (1<<countOfReqSkills);
        vector<long long> dp(m,(1ll<<countOfPeople)-1);
        dp[0] = 0ll;
        
        for(int skillsMask=1; skillsMask<m; skillsMask++)
        {
            for(int i=0; i<countOfPeople; i++)
            {
                smallerTeamMask = skillsMask &(~skillMaskPeople[i]);
                if(smallerTeamMask != skillsMask)
                {
                    long long peopleMask = dp[smallerTeamMask] | (1ll<<i);
                    if(__builtin_popcountll(peopleMask) < __builtin_popcountll(dp[skillsMask]))
                        dp[skillsMask] = peopleMask;
                }
            }
        }
        
        vector<int> team;
        for(int i=0; i<countOfPeople; i++)
        {
            if(dp[m-1]&(1ll<<i))
                team.push_back(i);
        }
        return team;
    }
};
