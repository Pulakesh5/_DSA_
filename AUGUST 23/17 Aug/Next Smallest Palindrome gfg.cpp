class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
        vector<int> v(num, num+n);
        int left = n/2, right = n/2;
        
        if((n&1) == 0)
            left--;
	    
	    while(left>=0)
	    {
	        if(v[right]>v[left])
	            break;
	        if(v[left]>v[right]) //match the most significant digit in the second half which is < its counterpart 
	        {
	            while(left>=0) //make the rest of second half equal to the first half
	            {
	                v[right] = v[left];
	                left--;
	                right++;
	            }
	            return v; // this is the final answer
	        }
	        left--;
	        right++;
	    }
	    
	    left = n/2;
	    right = n/2;
	    if((n&1) == 0)
	        left--;
	    // increase the first half to make it pallindrome
	    while(left>=0)
	    {
	        if(num[left]!=9)
	        {
	            // increase the least significant digit which is less than its counterpart
	            if(num[right] >= num[left])
	                num[left]++;
	            //match the digits of the both halves
	            while(left>=0) 
	            {
	                num[right] = num[left];
	                left--;
	                right++;
	            }
	            for(int i=0; i<n; i++)
	                v[i] = num[i];
	            return v;//this is the final answer
	        }
            // make the LSDs of 1st half and MSDs of 2nd half 0, which are 9, e.g: if first half looks like ..699 then after change if would be ..700 	        
	        else 
	        {
	            num[left] = 0;
	            num[right] = 0;
	            left--;
	            right++;
	        }
	    }
	    // if all the 1st half digits are 9 then make a new array which is longer than actual num array by 1 more digit
	    // it contains the MSD as 1, as well as the LSD is also 1 (for pallindrome sake) and rest of the digits are 0
	    vector<int> answer(n+1,0);
	    answer[0] = 1;
	    answer[n] = 1;
	    return answer;
	}

};
