class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int res=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int s=players[0];
        int l=trainers[trainers.size()-1];
        int t=0,p=0;
        for(int j=0;j<trainers.size();j++)
        {
            if(trainers[j]>=s) t++;
        }
        for(int j=0;j<players.size();j++)
        {
            if(players[j]<=l) p++;
        }
        return min(t,p);
    }
};