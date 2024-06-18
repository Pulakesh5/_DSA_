class Solution {
  public:
    int rectanglesInCircle(int r) {
        int count=0;
        for(int l=1;l<2*r;l++){
            for(int w=1;w<2*r;w++){
                if(l*l+w*w<=4*r*r)
                    count++;
            }
        }
        return count;
    }
};
