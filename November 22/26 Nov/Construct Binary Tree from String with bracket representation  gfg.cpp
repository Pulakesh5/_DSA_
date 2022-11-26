class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        int n=str.size();
        // for(int i=0;i<n;i++) cout<<str[i]<<"  ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<i<<"  ";
        // cout<<endl;
        
        return rec(str,0,n-1);
    }
private:
    Node* rec(string str, int s, int e)
    {
        if(s>e) return NULL;
        
        if(s==e){
            //cout<<"called :"<<s<<", "<<e<<endl;
            return new Node(str[s]-'0');
        }
        
        int num=0,cnt=0;
        //cout<<"called :"<<s<<", "<<e<<endl;
        while(s<=e && str[s]!='(')
        {
            num=num*10+(str[s]-'0');
            s++;
        }
        Node* node= new Node(num);
        //cout<<"s : "<<s<<" num = "<<num<<endl;
        for(int i=s;i<=e;i++)
        {
            if(str[i]=='(') cnt++;
            if(str[i]==')') cnt--;
            if(cnt==0)
            {
                node->left=rec(str,s+1,i-1);
                node->right=rec(str,i+2,e-1);
                break;
            }
        }
        return node;
    }
};
