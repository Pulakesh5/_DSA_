    int solve(int x, int y) {
        // code here
    
        if(x==y) return 0;
        
        if((y&x)==x || (y&x)==y) return 1;
        
        return 2;
        
    }
