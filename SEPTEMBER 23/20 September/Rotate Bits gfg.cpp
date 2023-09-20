{
  public:
    vector <int> rotate (int n, int d)
    {
        //code here.
        d%=16;
        bitset<16> left(n), right(n);
        
        bitset<16> lr = (left<<d) | (left>>(16-d));
        bitset<16> rr = (right>>d) | (right<<(16-d));
        
        vector<int> rotated;
        rotated.push_back(lr.to_ulong());
        rotated.push_back(rr.to_ulong());
        return rotated;
    }
};
