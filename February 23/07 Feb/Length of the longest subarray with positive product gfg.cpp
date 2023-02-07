        int maxLength(vector<int> &arr,int n){
           //code here
            int i=0;
            int longest=0;
            while(i<n)
            {
                // breaking the array in segments containing no 0
                while(i<n && arr[i]==0)
                    i++;
                
                int lp=-1, rp=-1;
                int ind=i;
                int negCount=0;
                
                while(ind<n && arr[ind]!=0)
                {
                    if(arr[ind]<0)
                    {
                        negCount++;
                        if(lp==-1) lp=ind;
                        rp=ind;
                    }
                    ind++;
                }
                if(negCount%2==0)
                    longest=max(longest,ind-i);
                else
                {
                    if(lp!=-1)//removing first neg element
                        longest=max(longest, ind-lp-1);
                    if(rp!=-1)//removing last neg element
                        longest = max(longest, rp-i);
                }
                // if arr[ind] = 0, skipping it and starting from next 
                i=ind+1;
            }
            
            return longest;
        }
