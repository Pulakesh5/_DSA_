class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto &a, auto &b){return a[1]<b[1];});
        
        priority_queue<int> pq;
        
        int n=courses.size(),time=0,total=0;
        int duration,end;
        
        for(int i=0;i<n;i++){
            duration=courses[i][0];
            end=courses[i][1]; 
            if(time+duration <= end){
                time+=duration;
                pq.push(duration);
            }
            else if(pq.size() && pq.top()>duration){
                time+=duration - pq.top();
                pq.pop(); 
                pq.push(duration);
            }
        }
        return pq.size();
    }
};
