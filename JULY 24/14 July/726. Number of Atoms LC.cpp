class Solution {
public:
    string countOfAtoms(string formula) {
        int len = formula.size();
        stack<unordered_map<string,int>> stk;
        unordered_map<string, int> resultCounter;
        int i=0;
        while(i<len)
        {
            
            if(formula[i]=='(')
            {
                i++;
                stk.push(unordered_map<string,int>());
                continue;
            }

            if(formula[i]==')')
            {
                string count="";
                i++;
                while(i<len && isdigit(formula[i]))
                {
                    count.push_back(formula[i]);
                    i++;
                }
                int _count = count.empty() ? 1: stoi(count);
                unordered_map<string,int> lastCounter = stk.top();
                stk.pop();
                unordered_map<string,int>& target = stk.empty() ? resultCounter : stk.top();
                for(const auto& [element, counter] : lastCounter)
                {
                    target[element] += (counter * _count);
                }
                continue;
            }

            string curElement = "";
            string curStringCounter = "";
            unordered_map<string, int>& target = stk.empty() ? resultCounter: stk.top();

            while(i<len && formula[i]!='(' && formula[i]!=')')
            {
                if(isalpha(formula[i]))
                {
                    if(isupper(formula[i]) && !curElement.empty())
                    {
                        target[curElement] += curStringCounter.empty() ? 1: stoi(curStringCounter);
                        curElement = "";
                        curStringCounter = "";
                    }
                    curElement.push_back(formula[i]);
                }
                else
                {
                    curStringCounter.push_back(formula[i]);
                }
                i++;
            }
            target[curElement] += curStringCounter.empty() ? 1: stoi(curStringCounter);
        }

        vector<string> parts;
        for(const auto [element, counter]:resultCounter)
        {
            parts.push_back(element+(counter==1 ? "" : to_string(counter)));
        }
        sort(parts.begin(), parts.end());
        string elementCount = "";
        for(const auto &part:parts)
            elementCount+=part;
        
        return elementCount;
    }
};
