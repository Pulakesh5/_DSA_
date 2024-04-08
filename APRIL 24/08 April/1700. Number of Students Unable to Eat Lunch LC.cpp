class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> student(2);
        for(int stdnt:students)
            student[stdnt]++;
        int index = 0, n = students.size();
        for(; index<n && student[sandwiches[index]]>0; index++)
            student[sandwiches[index]]--;
        return (n-index);
    }
};
