    def inSequence(self, A, B, C):
        # code here
        return 0 if (B<A and C>0 or B>A and C<0) else  1 if(C!=0 and (B-A)%C == 0 or (B-A)==0) else 0;
