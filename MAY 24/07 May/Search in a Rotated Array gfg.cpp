class Solution {
  public:
    int search(int A[], int l, int h, int key) {
        // l: The starting index
        // h: The ending index, you have to search the key in this range

        // complete the function here
        int rotationPoint = -1;
        for(int i=1; i<=h; i++)
        {
            if(A[i-1]>A[i])
            {
                rotationPoint = i-1;
                break;
            }
        }
        int index;
        if(rotationPoint==-1)
        {
            index = lower_bound(A, A+h+1, key) - A;   
            if(index==(h+1) || A[index]!=key)
                return -1;
            return index;
        }
        if(key>=A[l])
        {
            index = lower_bound(A, A+rotationPoint+1, key) - A;   
            if(index==(rotationPoint+1) || A[index]!=key)
                return -1;
            return index;
        }
        else if(key>=A[rotationPoint+1])
        {
            index = lower_bound(A+rotationPoint+1, A+h+1, key) - A;   
            if(index==(h+1) || A[index]!=key)
                return -1;
            return index;
        }
        
        return -1; 
    }
};
