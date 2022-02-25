class Solution{   
public:
    string moveRobots(string s1, string s2){
        // code here 
        int p1=0,p2=0,n=s1.length();
        while(p1<n && p2<n){
            if(s1[p1]=='#') // passing empty spaces of s1
                p1++;
            else if(s2[p2]=='#') // passing empty spaces of s2
                p2++;
            else if(s1[p1]!=s2[p2]) // non-empty spaces are not captured by similar bots
                return "No";
            else if(s1[p1]=='A' && p1<p2) // bot A appears left of it
                return "No";
            else if(s1[p1]=='B' && p1>p2) // bot B appears right of it
                return "No";
            else{   // bots are there where they should be
                p1++;p2++;
            }
        }
        return "Yes";
    }
};
