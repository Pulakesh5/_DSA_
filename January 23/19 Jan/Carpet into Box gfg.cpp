    int carpetBox(int L, int W, int C, int D){
        //code here
        //without rotation
        int move=0,move_wo=0;
        int _L=L,_W=W;
        
        while(L>C)
        {
            L/=2;
            move_wo++;
        }
        while(W>D)
        {
            W/=2;
            move_wo++;
        }
        
        //with rotation
        L=_W;
        W=_L;
        while(L>C)
        {
            L/=2;
            move++;
        }
        while(W>D)
        {
            W/=2;
            move++;
        }
        return min(move,move_wo);
    }
