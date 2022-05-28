class Solution{   
public:
    int shortestPath( int x, int y){ 
        if(x==y) return 0;
        
        int path=0;
        int mx=max(x,y),mn=min(x,y);
        while(mx!=mn){
            mx/=2;
            path++;
            if(mx<mn){
                mn/=2;
                path++;
            }
        }
        return path;
    }
};
