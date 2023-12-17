#define pis pair<int,string>
class FoodRatings {
public:
    map<string, int> foodRating;
    map<string, string> food_cuisine;
    map<string, set<pis>> bestRatings;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int length = foods.size();
        for(int i=0; i<length; i++)
        {
            foodRating[foods[i]] = ratings[i];
            food_cuisine[foods[i]] = cuisines[i];
            bestRatings[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int currRating = foodRating[food];
        foodRating[food] = newRating;
        string cuisine = food_cuisine[food];
        auto itr = bestRatings[cuisine].find({-currRating, food});
        bestRatings[cuisine].erase(itr);
        bestRatings[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto itr = bestRatings[cuisine].begin();
        return (*itr).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
