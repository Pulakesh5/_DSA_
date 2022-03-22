class Solution {
  public:
    int minRepeats(string A, string B) {
        int i = 0;
        while(i < A.length()) {
            if(A[i] == B[0]) {
                bool flag = true;
                int k = 1;
                for(int j=0; j<B.length(); j++) {
                    if(A[(i+j)%A.length()] != B[j]) {
                        flag = false;
                        break;
                    }
                    else if((i+j)%A.length() == 0) k++;
                }
                if(flag) return i?k:k-1;
            }
            i++;
        }
        
        return -1;
    }
};
