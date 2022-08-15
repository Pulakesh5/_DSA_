class Solution{
 public:
   // function should return the number of turns required to go from first node to second node 
   Node* LCA(struct Node* root, int first, int second)
   {
       if(root==NULL)
           return NULL;
       if(root->data==first or root->data==second)
           return root;
       Node* lft=LCA(root->left,first,second);
       Node* rt=LCA(root->right,first,second);
       if(lft!=NULL && rt!=NULL)
           return root;
       else
       if(lft!=NULL)
           return lft;
       else
       return rt;
   }
   long cnt(Node* r,int num,int dir)
   {
       if(r==NULL)
           return INT_MAX;
       if(r->data==num)
           return 0;
       if(dir==0)
       {
           long op1=cnt(r->left,num,1);
           long op2=cnt(r->right,num,2);
           return min(op1,op2);
       }
       else
       if(dir==1)
       {
           long op1=cnt(r->left,num,1);
           long op2=1+cnt(r->right,num,2);
           return min(op1,op2);
       }
       else
       if(dir==2)
       {
           long op1=1+cnt(r->left,num,1);
           long op2=cnt(r->right,num,2);
           return min(op1,op2);
       }
   }
   int NumberOFTurns(struct Node* root, int first, int second)
   {
     // Your code goes here
     Node* lca=LCA(root,first,second);
    // cout<<lca->data<<endl;
     long a=cnt(lca,first,0);
     long b=cnt(lca,second,0);
     //cout<<a<<" "<<b<<endl;
     if(lca->data==first or lca->data==second)
       return a+b;
     else
       return a+b+1;
     return 0;
   }
};
