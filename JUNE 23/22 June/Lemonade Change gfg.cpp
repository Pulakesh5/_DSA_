bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int five=0, ten=0;
        for(int bill:bills)
        {
            if(bill==5)
                five++;
            else if(bill==10)
            {
                if(five==0)
                    return false;
                five--;
                ten++;
            }
            else
            {
                if(ten==0 && five<3 )
                    return false;
                if(five==0)
                    return false;
                if(ten)
                {
                    ten--;
                    five--;
                }
                else
                    five-=3;
            }
        }
        return true;
    }
