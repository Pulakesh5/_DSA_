class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevDevice=0, device, lasers;
        for(string row:bank)
        {
            device=0;
            for(char d:row)
                device+=(d=='1');
            
            if(device>0)
            {
                cout<<prevDevice<<" "<<device<<endl;
                lasers+=(prevDevice*device);
                prevDevice=device;
            }
        }
        return lasers;
    }
};
