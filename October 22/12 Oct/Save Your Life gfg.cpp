      string maxSum(string w,char x[], int b[],int n){
          // code here    
          vector<int> ascii(256);
          for(int i=60;i<125;i++)
          {
              ascii[i]=i;
          }
          for(int i=0;i<n;i++)
          {
              ascii[(int)(x[i])]=b[i];
          }
          
          n=w.size();
          int sum=0,maxSubSum=INT_MIN;
          string subStr="",maxSub="";
          for(int i=0;i<n;i++)
          {
              //cout<<w[i]<<" "<<ascii[w[i]]<<" ";
              sum+=ascii[w[i]];
              subStr.push_back(w[i]);
              //cout<<subStr<<" "<<sum<<endl;
              if(maxSubSum<sum)
              {
                  maxSubSum=sum;
                  maxSub=subStr;
              }
              if(sum<0)
              {
                  sum=0;
                  subStr="";
              }
              
          }
          return maxSub;
      }
