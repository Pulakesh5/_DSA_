int minElement;
stack<int> _push(int arr[],int n)
{
   // your code here

   stack<int> stk;
   
   for(int i=0;i<n;i++){
       if(stk.empty()){
           stk.push(arr[i]);
           
           minElement=arr[i];
           //cout<<"pushed "<<arr[i]<<" "<<minElement<<endl;
       }
       else if(arr[i]>=minElement){
           stk.push(arr[i]);
           //cout<<"pushed "<<arr[i]<<" "<<minElement<<endl;
       }
       else{
           stk.push(2*arr[i]-minElement);
           //cout<<"pushed "<<2*arr[i] - minElement<<" "<<minElement<<endl;
           minElement=arr[i];
       }
   }
   return stk;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>stk)
{
    // your code here
    while(!stk.empty()){
        if(stk.top()>=minElement){
            cout<<minElement<<" ";
        }
        else{
            cout<<minElement<<" ";
            minElement=2*minElement-stk.top();
        }
        stk.pop();
    }
    
}
