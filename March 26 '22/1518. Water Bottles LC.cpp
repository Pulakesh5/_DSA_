class Solution {
public:
    int numWaterBottles(int Bottles, int Exchange) {
        int ans=Bottles;
        int full=0,empty=Bottles;
        while(empty && empty>=Exchange){
            full = empty/Exchange;
            ans+=full;
            empty%=Exchange;
            empty+=full;
        }
    return ans;
    
    }
};

/*
Every time you trade in numExchange bottles, you get one bottle back.
Therefore you decrease your number of bottles by (numExchange - 1) and increase your answer by 1.
This suggests a simple division, where you can just divide numBottles by (numExchange - 1).
The reason this doesn't work, is that you can't end up with zero bottles. 
For example if you have 4 bottles and numExchange is 5, you can't trade and wind up with 0 bottles; you can't trade at all.
So, you subtract one from each of the numbers you're given, and then divide. 
That says how many full bottles you can get by trading. Add to that the number of bottles you started with
*/
class Solution {
public:
    int numWaterBottles(int Bottles, int Exchange) {
        int ans=(Bottles-1)/(Exchange-1);
        ans+=Bottles;
    return ans;
    
    }
};
/*
Taking the wiki solution for the geometric series to the nth term, we get a(1-r^n) / (1-r),
where r is our (1/numExchange), and n is the number of steps, or 1 + # exchanges we want from the series(counting the 0th exchange as 1), and a = numBottles.

n = log_numExchange (numBottles) + 1, the one counting the first term with r^0

for example, if we have 9 bottles, and exchange rate of 3, the number of exchanges we can do is equal to the log (base 3) of 9 = 2.

In this example, a*r^n = r is demonstrated by 9 * (1/3)^(2+1) = 1/3

Simplifying the equation gives:
a(1-r^n) / (1-r)
= (a - a*r^n) / (1-r)
= (a - r) / (1-r)
This line here is represented by

numBottles-numExchange**-1)//(1 - numExchange**-1)
*/
class Solution {
public:
    int numWaterBottles(int Bottles, int Exchange) {
        
    return (Bottles*Exchange-1)/(Exchange-1);
    
    }
};
