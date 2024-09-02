class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    int chalkReplacer(vector<int>& chalk, int k) {
        int N = chalk.size();
        long long sum = 0;
        sum = accumulate(chalk.begin(), chalk.end(), sum);
        k = k%sum;
        for(int i=0; i<N; i++)
        {
            k = k - chalk[i];
            if(k<0)
                return i;
        }
        return -1; 
    }
};
