int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        map<int,int> nums;
        int num, lim;
        int special=0;
        for(int i=0;i<N;i++) nums[arr[i]]++;
        for(int i=0;i<N;i++)
        {
            lim=sqrt(arr[i]);
            num=arr[i];
            if(nums[num]>1 || nums.find(1)!=nums.end())
            {
                if(num==1 && nums[1]==1)
                    continue;
                special++;
                //cout<<"count of "<<num<<" more than 1 "<<endl;
            }
            else if(num>1)
            {
                for(int d=2;d<=lim;d++)
                {
                    if((num%d)==0 && (nums.find(d)!=nums.end() || nums.find(num/d)!=nums.end()))
                    {
                        special++;
                        //cout<<num<<" divides by "<<d<<endl;
                        break;
                    }
                }
            }
            
        }
        return special;
    }
