class FoodRatings {
public:
    map<string,int> foodRating;
    map<string,string> food_cuisine;
    map<string,set<pair<int,string>>> bestRated;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
            foodRating[foods[i]]=ratings[i];
            food_cuisine[foods[i]] = cuisines[i];
            bestRated[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int currRating = foodRating[food];
        string cuisine = food_cuisine[food];
        foodRating[food] = newRating;
        bestRated[cuisine].erase(bestRated[cuisine].find({-currRating,food}));
        bestRated[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        //return bestRated[cuisine].begin()->second;
        auto it=bestRated[cuisine].begin();
        return (*it).second;
    }
};
