class Solution{
    int minEle = 101;
    stack<int> s, aux;
    public:
    
       /*returns min element from stack*/
       int getMin(){
            if(s.empty())
                return -1;
           return minEle;
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
            if(s.empty())
                return -1;
            int top = s.top();
            s.pop();
            aux.pop();
            if(aux.empty())
                minEle = 101;
            else
                minEle = aux.top();
            return top;
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
            if(x<minEle)
                minEle = x;
            aux.push(minEle);
            s.push(x);
           //Write your code here
       }
};
