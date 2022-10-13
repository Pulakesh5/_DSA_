class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        int n=students.size();
        vector<int> count(2,0);
        for(int i=0;i<n;i++)
            count[students[i]]++;
        int k;
        for(k=0;k<n && count[sandwiches[k]]>0;k++)
            count[sandwiches[k]]--;
        return (n-k);
    }
};
