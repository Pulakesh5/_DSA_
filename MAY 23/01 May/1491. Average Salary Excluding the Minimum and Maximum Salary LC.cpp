class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double totalSalary=0;
        int n=salary.size();
        for(int i=1;i<(n-1);i++)
            totalSalary+=salary[i];
        return (totalSalary/(n-2));
    }
};
