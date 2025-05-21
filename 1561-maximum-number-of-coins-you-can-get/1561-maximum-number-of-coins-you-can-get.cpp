class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int count=piles.size()/3;
        int score=0;
        for(int i=piles.size()-2;(i>=0 && count>0);i-=2){
            score+=piles[i];
            count--;
        }
        return score;
    }
};