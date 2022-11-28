class Solution{
    int sum, j;
    void subSum(int a[], int n, int i) {
        sum = 0;
        while (i < n && a[i] >= 0) {
            sum += a[i];
            i++;
        }
        j = i - 1;
    }
public:
	vector<int> findSubarray(int a[], int n) {
	    bool flag = true;
        vector<int> res;
        int ri = 0, rj = 0, resSum = 0;
        int i = 0;
        while (i < n) {
            if (a[i] >= 0) {
                flag = false;
                subSum(a, n, i);
                if (sum > resSum || (sum == resSum && rj - ri > j - i)) {
                    ri = i;
                    rj = j;
                    resSum = sum;
                }
                i = j;
            }
            i++;
        }
        if (flag)
            return {-1};
        for (i = ri; i <= rj; i++) {
            res.push_back(a[i]);
        }
        return res;}
};
