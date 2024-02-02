class Solution {
public:
    void backtrack(long num, vector<int> &seqNums, int low, int high)
    {
        if(num>high)
            return;
        if(num>=low && num<=high)
            seqNums.push_back(num);

        if((num%10)<9 && num<=(high/10))
            backtrack(num*10+(num%10)+1, seqNums, low, high);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> seqNums;
        long num=low;
        while(num>=10)
            num = num/10;
        for(long start=1; start<10; start++)
            backtrack(start, seqNums, low, high);
        sort(seqNums.begin(), seqNums.end());
        return seqNums;
    }
};
