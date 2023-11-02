class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) {
        // code here
        int mindist=n, dist_x=-1, dist_y=-1;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==x)
            {
                if(dist_y!=-1)
                    mindist = min(mindist, i-dist_y);
                dist_x = i;
            }
            if(arr[i]==y)
            {
                if(dist_x != -1)
                    mindist = min(mindist, i-dist_x);
                dist_y = i;
            }
        }
        if(dist_x==-1 || dist_y==-1)
            return -1;
        return mindist;
    }
};
