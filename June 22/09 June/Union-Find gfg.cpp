class Solution
{
    public:
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank1[]) 
    {
        int set_a=find(a,par),set_b=find(b,par);
        
        if(set_a==set_b)
            return;
        else if(rank1[set_a]<rank1[set_b]){
            par[set_a]=set_b;
        }
        else if(rank1[set_b]<rank1[set_a]){
            par[set_b]=set_a;
        }
        else{
            par[set_a]=set_b;
            rank1[set_b]+=1;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        return find(x,par)==find(y,par);
    }
    int find(int i, int par[]){
        if(par[i]!=i)
        {
            par[i]=find(par[i],par);
        }
        return par[i];
    }
};
