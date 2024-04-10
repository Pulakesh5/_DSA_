class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int len = deck.size();
        sort(deck.rbegin(), deck.rend());
        deque<int> dq;
        dq.push_back(deck[0]);
        for(int i=1; i<len; i++)
        {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
        }
        vector<int> revealedDeck(dq.begin(), dq.end());
        return revealedDeck;
    }
};
