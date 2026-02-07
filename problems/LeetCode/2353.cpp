#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
private:
    unordered_map<string, pair<int, string>> foodInfo;
    unordered_map<string, set<pair<int, string>>> cuisineFoods; 

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodInfo[foods[i]] = {ratings[i], cuisines[i]};
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [oldRating, cuisine] = foodInfo[food];
        cuisineFoods[cuisine].erase({-oldRating, food});
        cuisineFoods[cuisine].insert({-newRating, food});
        foodInfo[food].first = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineFoods[cuisine].begin()->second;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<string> foods(n), cuisine(n);
    vector<int> ratings(n);
    
    FoodRatings sol(foods, cuisine, ratings);
    

    return 0;
}