class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.rbegin(),people.rend());
        int boat=0;
        int n=people.size();
      
        int i=0,j=n-1;
        while(i<=j){
            if(people[i]+people[j]<=limit)
                j--;
            i++;
        }
        //if(people[n-1]!=-1) boat++;
        return i;
    }
};
