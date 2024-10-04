class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int teamTotal = skill[0]+skill[n-1];
        int l=1, r=n-2;
        long long totalSkill = 1ll*skill[0]*skill[n-1];

        while(l<r)
        {
            if(skill[l]+skill[r]!=teamTotal)
                return -1;
            totalSkill += (1ll*skill[l]*skill[r]);
            l++;
            r--;
        }
        return totalSkill;
    }
};
