static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mod_frequency(k);
        for(int num:arr)
            mod_frequency[(num%k+k)%k]++;
        if(mod_frequency[0]&1)
            return false;
        
        for(int i=1; i<=(k/2); i++)
        {
            if(mod_frequency[i]!=mod_frequency[k-i])
                return false;
        }
        return true;
    }
    //1 2 3 4 0 0 1 2 3 4
};
