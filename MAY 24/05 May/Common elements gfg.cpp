class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            
            vector<int> commons, aux;
            int p1=0, p2=0, p3=0;
            while(p1<n1 && p2<n2 )
            {
                if(A[p1]==B[p2])
                {
                    if(aux.empty() || aux.back()!=A[p1])
                        aux.push_back(A[p1]);
                    p1++;
                    p2++;
                }
                else if(A[p1]<B[p2])
                    p1++;
                else
                    p2++;
            }
            if(aux.empty())
                return {};
            int len = aux.size(), p=0;
            while(p<len && p3<n3)
            {
                if(aux[p]==C[p3])
                {
                    if(commons.empty() || commons.back()!=C[p3])
                        commons.push_back(C[p3]);
                    p++;
                    p3++;
                }
                else if(aux[p]<C[p3])
                    p++;
                else
                    p3++;
            }
            return commons;
        }

};
