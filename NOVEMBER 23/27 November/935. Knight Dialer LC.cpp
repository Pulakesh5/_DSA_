class Solution {
public:
    int knightDialer(int n) {
        long long MOD = 1e9+7;
        vector<vector<long long>>  phoneNumbers(2,vector<long long>(10,0)); 
        // phoneNumbers[i] = #phoneNumbers starting with j
        for(int i=0; i<10; i++)
        {
            phoneNumbers[0][i] = 1; 
        }
        for(int i=1; i<=(n-1); i++)
        {
            phoneNumbers[1][0] = (phoneNumbers[0][4] + phoneNumbers[0][6])%MOD;
            phoneNumbers[1][1] = (phoneNumbers[0][6] + phoneNumbers[0][8])%MOD;
            phoneNumbers[1][2] = (phoneNumbers[0][7] + phoneNumbers[0][9])%MOD;
            phoneNumbers[1][3] = (phoneNumbers[0][4] + phoneNumbers[0][8])%MOD;
            phoneNumbers[1][4] = (phoneNumbers[0][3] + phoneNumbers[0][9] + phoneNumbers[0][0])%MOD;
            phoneNumbers[1][5] = 0;
            phoneNumbers[1][6] = (phoneNumbers[0][0] + phoneNumbers[0][1] + phoneNumbers[0][7])%MOD;
            phoneNumbers[1][7] = (phoneNumbers[0][2] + phoneNumbers[0][6])%MOD;
            phoneNumbers[1][8] = (phoneNumbers[0][1] + phoneNumbers[0][3])%MOD;
            phoneNumbers[1][9] = (phoneNumbers[0][2] + phoneNumbers[0][4])%MOD;
            swap(phoneNumbers[0], phoneNumbers[1]);
        }
        long long phoneNumbersCount=0;
        for(int i=0; i<10; i++)
            phoneNumbersCount = (phoneNumbersCount + phoneNumbers[0][i])%MOD;
        return phoneNumbersCount;
    }
};
