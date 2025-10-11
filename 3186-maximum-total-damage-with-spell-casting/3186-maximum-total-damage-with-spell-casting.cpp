class Solution {
public:
    vector<int> powerArr;
    unordered_map<int, long long> freq;
    vector<long long> memo;

    long long solve(int ind) {
        if(ind >= powerArr.size()) return 0;
        if(memo[ind] != -1) return memo[ind];
        long long not_take = solve(ind + 1);
        long long take = 0;
        if(ind == 0 || powerArr[ind] != powerArr[ind - 1]) {
            take = freq[powerArr[ind]];
            int next = ind + 1;
            while(next < powerArr.size() && powerArr[next] <= powerArr[ind] + 2) next++;
            take += solve(next);
        }

        return memo[ind] = max(take, not_take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        freq.clear();
        powerArr = power;
        sort(powerArr.begin(), powerArr.end());
        for(int x : power) freq[x] += x;

        memo.assign(powerArr.size(), -1);
        return solve(0);
    }
};