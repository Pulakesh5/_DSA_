class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // priority_queue sorted according to non-increasing beauty, price
        priority_queue<vector<int>> pq;
        for(auto item:items)
        {
            pq.push({item[1], item[0]});
        }
        //make auxiliary array with query clubbed with index
        int q_len = queries.size();
        vector<int> answer(q_len);
        vector<pair<int,int>> q_index_sorted(q_len);
        for(int i=0; i<q_len; i++)
        {
            q_index_sorted[i] = {queries[i], i};
        }
        sort(q_index_sorted.begin(), q_index_sorted.end());
        // find answer
        int index = q_len-1;
        while(index>=0)
        {
            if(pq.empty())
                break;

            if(pq.top()[1] > q_index_sorted[index].first)
                pq.pop();
            else
            {
                answer[q_index_sorted[index].second] = pq.top()[0];
                index--;
            }
        }
        // return answer
        return answer;
    }
};
