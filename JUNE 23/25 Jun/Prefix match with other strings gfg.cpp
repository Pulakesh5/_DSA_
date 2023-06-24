
class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
         int count=0;
        for(int i=0;i<n;i++){
            string temp=arr[i];
            for(int j=0;j<k;j++){
                if(temp[j]!=str[j]){
                    count++;
                    break;
                }
            }
        }
        return n-count;
    }
};
