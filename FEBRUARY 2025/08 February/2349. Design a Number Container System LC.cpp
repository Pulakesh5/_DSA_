class NumberContainers {
public:
    unordered_map<int, int> indexToNum;
    unordered_map<int, set<int>> numToIndex;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNum.find(index)!=indexToNum.end())
        {
            int prevNum = indexToNum[index];
            numToIndex[prevNum].erase(index);
            if(numToIndex[prevNum].size()==0)
                numToIndex.erase(prevNum);
        }
        indexToNum[index] = number;
        numToIndex[number].insert(index);
    }
    
    int find(int number) {
        if(numToIndex.find(number)==numToIndex.end())
            return -1;
        return *numToIndex[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
