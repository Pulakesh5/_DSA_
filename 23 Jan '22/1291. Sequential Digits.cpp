/*Solution Idea: make all possible sequential digits in the range of [numer_of_digit(low),numer_of_digit(high)]
                 from 1 to 9 with length in the range make all possible nums 
                 and keep pushing inn avector while they are in the range of [low,  high]              
*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums;
        int l=num_digit(low),h=num_digit(high);
        //string lower=to_string(low),higher=to_string(high);
        //cout<<l<<" "<<h<<'\n';
        for(int len=l;len<=h;len++){
        
            for(int start=1;start<=9;start++){
            
                int num=seq(start,len);
                //cout<<num<<" ";
                if(num>=low && num<=high)
                    nums.push_back(num);
            }
        }
        
        return nums;
    }
    int num_digit(int num){
        int count=0;
        while(num>0){
            count++;
            num/=10;
        }
        return count;
    }
    int seq(int start, int len){
        if(start+len-1>9)
            return 0;
        else{
            int num=start;
            for(int dig=1;dig<len;dig++){
                num=num*10+(start+dig);
            }
            return num;
        }
    }
    
};
