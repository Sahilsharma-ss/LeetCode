class Solution {
public:
    int minimumPairRemoval(vector<int>& arr) {
        int n = arr.size();
        vector<long long> nums(arr.begin(), arr.end());

        // doubly linked list
        vector<int> prev(n), next(n);
        prev[0] = -1;
        for (int i = 1; i < n; i++) prev[i] = i - 1;
        for (int i = 0; i < n - 1; i++) next[i] = i + 1;
        next[n - 1] = -1;

        // min-heap via set
        set<pair<long long, int>> st;
        for (int i = 0; i < n - 1; i++) {
            st.insert({nums[i] + nums[i + 1], i});
        }

        // count inversions (bad positions)
        int bad = 0;
        for (int i = 0; i < n; i++) {
            if (next[i] != -1 && nums[i] > nums[next[i]]) {
                bad++;
            }
        }

        int ops = 0;

        while (bad > 0) {
            auto [sum, idx] = *st.begin();
            st.erase(st.begin());

            int r = next[idx];
            int l = prev[idx];
            int rr = next[r];

            // remove old bad relations
            if (l != -1 && nums[l] > nums[idx]) bad--;
            if (nums[idx] > nums[r]) bad--;
            if (rr != -1 && nums[r] > nums[rr]) bad--;

            // erase outdated sums
            if (l != -1) st.erase({nums[l] + nums[idx], l});
            if (r != -1) st.erase({nums[idx] + nums[r], idx});
            if (rr != -1) st.erase({nums[r] + nums[rr], r});

            // merge idx and r
            nums[idx] += nums[r];

            // relink
            next[idx] = rr;
            if (rr != -1) prev[rr] = idx;

            // add new bad relations
            if (l != -1 && nums[l] > nums[idx]) bad++;
            if (rr != -1 && nums[idx] > nums[rr]) bad++;

            // insert new sums
            if (l != -1) st.insert({nums[l] + nums[idx], l});
            if (rr != -1) st.insert({nums[idx] + nums[rr], idx});

            ops++;
        }

        return ops;
    }
};
