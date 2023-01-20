  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      vector<int> count(N+1,0);
      
      int pr;
      
      for(int i=0;i<N;i++)
      {
          if(Edge[i]==-1) continue;
          count[Edge[i]]+=i;
      }
      int mxCount=-1, node=-1;
      //cout<<endl;
      for(int i=0;i<N;i++)
      {
          if(mxCount<=count[i])
          {
              mxCount=count[i];
              node=i;
          }
      }
      return node;
    
  }
