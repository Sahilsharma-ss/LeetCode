
class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = speed.size();
        int cnt = 0;

        int ind = n - 1;

        while (ind >= 0) {
            int sp = speed[ind];
            int b = position[ind];

            int j = ind - 1;

            while (j >= 0 && (speed[j] > sp || b - position[j] <= distance)) {
               b  = position[j];
               j--;
            }

            ind = j;
            cnt++;
        }

        return cnt;
    }
};

