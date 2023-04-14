int finLength(int N, vector<int> color, vector<int> radius) {
        stack<int> _col, _rad;
        for(int i=0;i<N;i++)
        {
            if(_col.empty())
            {
                _col.push(color[i]);
                _rad.push(radius[i]);
                continue;
            }
            if(_col.top()==color[i] && _rad.top()==radius[i])
            {
                _col.pop();
                _rad.pop();
            }
            else
            {
                _col.push(color[i]);
                _rad.push(radius[i]);
            }
        }
        return _col.size();
    }
