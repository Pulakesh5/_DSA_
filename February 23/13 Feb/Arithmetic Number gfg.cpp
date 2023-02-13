    int inSequence(int A, int B, int C){
        // code here
        return ((B<A&&C>0 || B>A&&C<0 )?0:( (C!=0&&(B-A)%C == 0 || (B-A)==0) ? 1:0));
    }
