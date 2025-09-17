class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>>map;
    unordered_map<string,string>foodtocuisine;
    unordered_map<string,int>foodtorating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++){
            map[cuisines[i]].insert({-ratings[i],foods[i]});
            foodtocuisine[foods[i]] = cuisines[i];
            foodtorating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodtocuisine[food];
        int oldrating = foodtorating[food];
        map[cuisine].erase({-oldrating,food});
        map[cuisine].insert({-newRating,food});
        foodtorating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return map[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */