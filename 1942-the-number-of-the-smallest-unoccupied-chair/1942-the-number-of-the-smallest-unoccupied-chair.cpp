class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<tuple<int,int,int>> arr;
        for(int i = 0; i < n; i++)
            arr.push_back({times[i][0], times[i][1], i});

        sort(arr.begin(), arr.end()); 

        // free chairs
        priority_queue<int, vector<int>, greater<int>> freeChairs;
        for(int i = 0; i < n; i++)
            freeChairs.push(i);

        // occupied chairs: {leaveTime, chair}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occupied;

        for(auto &[arrive, leave, idx] : arr) {

            // free chairs of people who left
            while(!occupied.empty() && occupied.top().first <= arrive) {
                freeChairs.push(occupied.top().second);
                occupied.pop();
            }

            int chair = freeChairs.top();
            freeChairs.pop();

            if(idx == targetFriend)
                return chair;

            occupied.push({leave, chair});
        }

        return -1;
    }
};
